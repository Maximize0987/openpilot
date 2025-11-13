import math
import capnp
import time
import os
import numpy as np
from collections import deque

from cereal import log
import cereal.messaging as messaging
from openpilot.common.numpy_fast import interp      #
from openpilot.common.filter_simple import FirstOrderFilter
from openpilot.common.realtime import config_realtime_process, Priority, Ratekeeper, DT_CTRL      #
from openpilot.selfdrive.car.interfaces import FRICTION_THRESHOLD
from openpilot.selfdrive.controls.lib.drive_helpers import MIN_SPEED, get_friction
from openpilot.selfdrive.controls.lib.latcontrol import LatControl
from openpilot.selfdrive.controls.lib.pid import PIDController
from openpilot.selfdrive.controls.lib.vehicle_model import ACCELERATION_DUE_TO_GRAVITY

# At higher speeds (25+mph) we can assume:
# Lateral acceleration achieved by a specific car correlates to
# torque applied to the steering rack. It does not correlate to
# wheel slip, or to speed.

# This controller applies torque to achieve desired lateral
# accelerations. To compensate for the low speed effects the
# proportional gain is increased at low speeds by the PID controller.
# Additionally, there is friction in the steering wheel that needs
# to be overcome to move it at all, this is compensated for too.

LL_CLOSE = 1.8
NUDGE_INPUT = [-1.58, -0.23, -0.08, 0.07, 1.42]
NUDGE_OUTPUT = [-0.08, -0.02, 0, 0.02, 0.08]

#KF_INPUT = [-2, -0.01, 0, 0.01, 2]
#KF_OUTPUT = [0.945, 0.96, 0.965, 0.965, 0.955]

KF_INPUT = [-1, 0, 1]
KF_LC = [1.08, 1, 0.95]
KF_RC = [0.95, 1, 1.08]
#KF_INPUT = [0, 10, 14]
#KF_OUTPUT = [1.1, 1, 0.9775]

KP = 1.0
KI = 0.3
KD = 0.0
KF = 0.955    # default base for curvature corrrection used in line 118

INTERP_SPEEDS = [1, 1.5, 2.0, 3.0, 5, 7.5, 10, 15, 30]
#KP_INTERP = [250, 120, 65, 30, 11.5, 5.5, 3.5, 2.0, KP]
#KP_INTERP = [188, 90, 49, 23, 8.6, 4.1, 2.6, 1.5, KP]        # 25% lower kp
KP_INTERP = [300, 144, 78, 36, 13.8, 6.6, 4.2, 2.4, KP]       # 20% higher kp

LP_FILTER_CUTOFF_HZ = 1.2
LAT_ACCEL_REQUEST_BUFFER_SECONDS = 1.0
VERSION = 0

class LatControlTorque(LatControl):
  def __init__(self, CP, CI, dt):
    super().__init__(CP, CI, dt)
    self.torque_params = CP.lateralTuning.torque
    self.torque_from_lateral_accel = CI.torque_from_lateral_accel()
    self.lateral_accel_from_torque = CI.lateral_accel_from_torque()
    self.pid = PIDController([INTERP_SPEEDS, KP_INTERP], KI, KD, rate=1/self.dt)
    self.update_limits()
    self.steering_angle_deadzone_deg = self.torque_params.steeringAngleDeadzoneDeg
    self.lat_accel_request_buffer_len = int(LAT_ACCEL_REQUEST_BUFFER_SECONDS / self.dt)
    self.lat_accel_request_buffer = deque([0.] * self.lat_accel_request_buffer_len , maxlen=self.lat_accel_request_buffer_len)
    self.previous_measurement = 0.0
    self.measurement_rate_filter = FirstOrderFilter(0.0, 1 / (2 * np.pi * LP_FILTER_CUTOFF_HZ), self.dt)

    self.sm = messaging.SubMaster(['pandaStates', 'carControl', 'liveCalibration', 'onroadEvents', 'frogpilotPlan'])
  
    self.last_nudge = 0
    self.no_nudge = 0
    self.no_kf = 0
    self.last_ll = 0
    self.last_rl = 0
    self.cycles = 0
    self.total_kf = 0
    self.hipcent = 0
    
  def update_live_torque_params(self, latAccelFactor, latAccelOffset, friction):
    self.torque_params.latAccelFactor = latAccelFactor
    self.torque_params.latAccelOffset = latAccelOffset
    self.torque_params.friction = friction
    self.update_limits()

  def update_limits(self):
    self.pid.set_limits(self.lateral_accel_from_torque(self.steer_max, self.torque_params),
                        self.lateral_accel_from_torque(-self.steer_max, self.torque_params))

  def update(self, active, CS, VM, params, steer_limited_by_safety, desired_curvature, curvature_limited, lat_delay, llk, model_data, frogpilot_toggles):
    pid_log = log.ControlsState.LateralTorqueState.new_message()
    pid_log.version = VERSION
    if not active:
      output_torque = 0.0
      pid_log.active = False
    else:
      left_lane = interp(5, model_data.laneLines[1].x, model_data.laneLines[1].y)
      ll = round(abs(left_lane), 2)
      right_lane = interp(5, model_data.laneLines[2].x, model_data.laneLines[2].y)
      rl = round(abs(right_lane), 2)
      lane_avg = left_lane + right_lane
      lane_val = interp(lane_avg, NUDGE_INPUT, NUDGE_OUTPUT)
      lane_avg = round(lane_avg, 2)
      self.sm.update(0)
      if CS.leftBlinker or CS.rightBlinker: # or CS.steeringPressed:
        self.no_nudge = self.sm.frame
      nudge_off = (self.sm.frame - self.no_nudge) * DT_CTRL < 3.6 # cooldown after blinker
      if CS.steeringPressed:
        self.no_kf = self.sm.frame
      kf_off = (self.sm.frame - self.no_kf) * DT_CTRL < 3.6 # cooldown after blinker
      if rl > 2.5 or abs(ll) > 2.5:
        self.last_ll = ll
        self.last_rl = rl   
        nudge_off = False
        kf_off = False
      measured_curvature = -VM.calc_curvature(math.radians(CS.steeringAngleDeg - params.angleOffsetDeg), CS.vEgo, params.roll)
      roll_compensation = params.roll * ACCELERATION_DUE_TO_GRAVITY
      curvature_deadzone = abs(VM.calc_curvature(math.radians(self.steering_angle_deadzone_deg), CS.vEgo, 0.0))
      lateral_accel_deadzone = curvature_deadzone * CS.vEgo ** 2

      delay_frames = int(np.clip(lat_delay / self.dt, 1, self.lat_accel_request_buffer_len))
      expected_lateral_accel = self.lat_accel_request_buffer[-delay_frames]
      # TODO factor out lateral jerk from error to later replace it with delay independent alternative
      future_desired_lateral_accel = desired_curvature * CS.vEgo ** 2     #   future_desired_lateral_accel = desired_curvature * CS.vEgo ** 2
      fdla1 = round(future_desired_lateral_accel, 3)
      future_desired_lateral_accel *= KF
      fdla2 = round(future_desired_lateral_accel, 3)
      fdla4 = 0
      if future_desired_lateral_accel > 0.1 and not kf_off:
        fdla = interp(lane_avg, KF_INPUT, KF_RC)
        future_desired_lateral_accel *= fdla
        fdla3 = round(future_desired_lateral_accel, 3)
        fdla4 = fdla3 / fdla1
        fdla4 = round(fdla4, 3)
        self.cycles = self.cycles + 1
        self.total_kf = self.total_kf + fdla4
        avg_kf = self.total_kf / self.cycles
      elif future_desired_lateral_accel < -0.1 and not kf_off: 
        fdla = interp(lane_avg, KF_INPUT, KF_LC)
        future_desired_lateral_accel *= fdla
        fdla3 = round(future_desired_lateral_accel, 3)
        fdla4 = fdla3 / fdla1
        fdla4 = round(fdla4, 3)
        self.cycles = self.cycles + 1
        self.total_kf = self.total_kf + fdla4
        avg_kf = self.total_kf / self.cycles
      if rl > ll < LL_CLOSE or ll > rl < LL_CLOSE and CS.vEgo > 22 and not nudge_off:
        future_desired_lateral_accel += lane_val
        self.last_nudge = lane_val
      if abs(fdla2) > 0.4 and not nudge_off and not kf_off:
        avg_kfp = round(avg_kf, 4)
        print(f"LA: {lane_avg} %: {fdla4} AVG: {avg_kfp}")
      self.lat_accel_request_buffer.append(future_desired_lateral_accel)
      gravity_adjusted_future_lateral_accel = future_desired_lateral_accel - roll_compensation
      desired_lateral_jerk = (future_desired_lateral_accel - expected_lateral_accel) / lat_delay

      measurement = measured_curvature * CS.vEgo ** 2
      measurement_rate = self.measurement_rate_filter.update((measurement - self.previous_measurement) / self.dt)
      self.previous_measurement = measurement

      setpoint = lat_delay * desired_lateral_jerk + expected_lateral_accel
      error = setpoint - measurement

      # do error correction in lateral acceleration space, convert at end to handle non-linear torque responses correctly
      pid_log.error = float(error)
      ff = gravity_adjusted_future_lateral_accel
      # latAccelOffset corrects roll compensation bias from device roll misalignment relative to car roll
      ff -= self.torque_params.latAccelOffset
      # TODO jerk is weighted by lat_delay for legacy reasons, but should be made independent of it
      ff += get_friction(error, lateral_accel_deadzone, FRICTION_THRESHOLD, self.torque_params)

      freeze_integrator = steer_limited_by_safety or CS.steeringPressed or CS.vEgo < 5
      output_lataccel = self.pid.update(pid_log.error,
                                       -measurement_rate,
                                        feedforward=ff,
                                        speed=CS.vEgo,
                                        freeze_integrator=freeze_integrator)
      output_torque = self.torque_from_lateral_accel(output_lataccel, self.torque_params)

      pid_log.active = True
      pid_log.p = float(self.pid.p)
      pid_log.i = float(self.pid.i)
      pid_log.d = float(self.pid.d)
      pid_log.f = float(self.pid.f)
      pid_log.output = float(-output_torque) # TODO: log lat accel?
      pid_log.actualLateralAccel = float(measurement)
      pid_log.desiredLateralAccel = float(setpoint)
      pid_log.desiredLateralJerk = float(desired_lateral_jerk)
      pid_log.saturated = bool(self._check_saturation(self.steer_max - abs(output_torque) < 1e-3, CS, steer_limited_by_safety, curvature_limited))

    # TODO left is positive in this convention
    return -output_torque, 0.0, pid_log
