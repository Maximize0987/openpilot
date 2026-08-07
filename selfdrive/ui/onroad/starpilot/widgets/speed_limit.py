import pyray as rl
from typing import Optional
from openpilot.common.params import Params
from openpilot.selfdrive.ui.ui_state import ui_state
from openpilot.selfdrive.ui.onroad.starpilot.widgets.base import LayoutWidget
from openpilot.selfdrive.ui.onroad.starpilot.slc_speed_limit import (
  _get_slc_state, render_speed_limit_at, SIGN_MARGIN,
  EU_SIGN_SIZE, US_SIGN_HEIGHT,
  SET_SPEED_WIDTH_MET, SET_SPEED_WIDTH_IMP
)


class SpeedLimitWidget(LayoutWidget):
  TOUCH_SLOP = 20

  def __init__(self):
    super().__init__("speed_limit", priority=2)
    self._slc_state: dict | None = None
    self._sign_rect: Optional[rl.Rectangle] = None

  @property
  def _hit_rect(self) -> rl.Rectangle:
    rect = self._sign_rect or self.rect
    slop = self.TOUCH_SLOP
    return rl.Rectangle(
      rect.x - slop,
      rect.y - slop,
      rect.width + 2 * slop,
      rect.height + 2 * slop,
    )

  @property
  def is_visible(self) -> bool:
    self._slc_state = _get_slc_state()
    if self._slc_state is None:
      self._sign_rect = None
      return False
    return True

  def get_size(self) -> tuple[float, float]:
    if self._slc_state is None:
      return 0.0, 0.0

    use_vienna = self._slc_state['use_vienna']
    ss_width = SET_SPEED_WIDTH_MET if ui_state.is_metric else SET_SPEED_WIDTH_IMP
    sign_width = ss_width - 2 * SIGN_MARGIN

    w = float(EU_SIGN_SIZE if use_vienna else sign_width)
    h = float(EU_SIGN_SIZE if use_vienna else US_SIGN_HEIGHT)

    return w, h

  def _render(self, rect: rl.Rectangle) -> None:
    if self._slc_state is None:
      return
    params = ui_state.ui_params
    expanded = params.get_bool("SpeedLimitSources")
    self._sign_rect = render_speed_limit_at(self._slc_state, rect, expanded)

  def _handle_mouse_press(self, mouse_pos) -> None:
    state = self._slc_state
    if state is None or not rl.check_collision_point_rec(mouse_pos, self._hit_rect):
      return

    if state['speed_limit_changed'] and state['unconfirmed_valid']:
      Params(memory=True).put_bool("SpeedLimitAccepted", True)
      return

    params = ui_state.ui_params
    current = params.get_bool("SpeedLimitSources")
    params.put_bool("SpeedLimitSources", not current)
