from openpilot.selfdrive.ui.onroad.starpilot.pip_sidecam import (
  IMAGE_TO_VEHICLE_SIDE,
  PIP_FRAGMENT_SHADER,
  PipSideCamera,
)


def test_pip_maps_raw_driver_image_sides_to_vehicle_sides():
  assert IMAGE_TO_VEHICLE_SIDE == {"left": "right", "right": "left"}

  camera = PipSideCamera.__new__(PipSideCamera)
  camera._closed = True
  camera._mask = {
    "center_left": [100, 200],
    "center_right": [900, 200],
    "crop_size": 100,
  }

  left_vehicle_crop = camera._crop_rect("left")
  right_vehicle_crop = camera._crop_rect("right")

  assert (left_vehicle_crop.x, left_vehicle_crop.y) == (850, 150)
  assert (right_vehicle_crop.x, right_vehicle_crop.y) == (50, 150)


def test_pip_driver_camera_shader_mirrors_the_crop():
  assert "uniform int uFlipX" in PIP_FRAGMENT_SHADER
  assert "cropCoord.x = 1.0 - cropCoord.x" in PIP_FRAGMENT_SHADER
