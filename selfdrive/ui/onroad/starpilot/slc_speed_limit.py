import math
from typing import Optional

import pyray as rl
from openpilot.common.constants import CV
from openpilot.selfdrive.ui.ui_state import ui_state
from openpilot.system.ui.lib.application import gui_app, FontWeight
from openpilot.system.ui.lib.multilang import tr
from openpilot.system.ui.lib.text_measure import measure_text_cached
from openpilot.selfdrive.ui.onroad.starpilot.widget_style import (
  CONTROL_BG, CONTROL_BORDER_WIDTH, SLC_HEIGHT,
  draw_control_card, roundness_for,
)

_WHITE = rl.Color(255, 255, 255, 255)

# ── Constants ─────────────────────────────────────────────────────────

# EU Vienna sign
EU_SIGN_SIZE = 176
EU_SIGN_WIDTH = 176
RED_RING_WIDTH = 20

# Pending sign blink cadence — 1s period, 50% duty cycle.
PENDING_BLINK_MS = 500

# Source display metadata: title, abbreviation, raw-value key (display order).
SOURCE_DEFS = [
  ("Dashboard", "Dash",   "dashboard_sl", "Dashboard", "dashboard"),
  ("Map Data",  "Maps",    "map_sl",       "Map",       "map"),
  ("Vision",    "Vision", "vision_sl",    "Camera",    "camera"),
  ("Mapbox",    "Mapbox", "mapbox_sl",    "Mapbox",    "map"),
  ("Upcoming",  "Next",   "next_sl",      "Navigation", "navigation"),
]

# Fonts
FONT_LABEL = 30
FONT_SPEED = 78
FONT_OFFSET = 30
FONT_EU_LARGE = 70
FONT_EU_SMALL = 60
FONT_EU_OFFSET = 40

# Vision speed-limit pulse — one-shot purple highlight when the active source
# is "Vision" and the resolved value just changed.
VISION_SPEED_LIMIT_PULSE_SECONDS = 1.0
VISION_SPEED_LIMIT_PULSE_COLOR = rl.Color(188, 132, 255, 255)
VISION_SPEED_LIMIT_CHANGE_THRESHOLD = 0.1  # m/s


# ── Vision speed-limit pulse state (one-shot highlight) ────────────────
# Persists across frames so we can detect a just-changed vision limit and
# animate the sign colors toward VISION_SPEED_LIMIT_PULSE_COLOR for
# VISION_SPEED_LIMIT_PULSE_SECONDS. Held at module scope because this file
# is a procedural API consumed once per frame by StarPilotOnroadView.

_pulse = {
  "active": False,        # is the active source currently "Vision"?
  "last": 0.0,            # last resolved vision limit (m/s) seen while active
  "start": -VISION_SPEED_LIMIT_PULSE_SECONDS,  # get_time() stamp of the last change
}


def _reset_pulse() -> None:
  """Clear pulse state when SLC goes hidden or stale."""
  _pulse["active"] = False
  _pulse["last"] = 0.0
  _pulse["start"] = -VISION_SPEED_LIMIT_PULSE_SECONDS


def _tick_pulse(source: str, resolved_ms: float) -> None:
  """Update pulse state once per frame from the resolved speed limit.

  The pulse fires when the active source is "Vision" and either the source
  just became active or the resolved value changed by at least
  VISION_SPEED_LIMIT_CHANGE_THRESHOLD (m/s).
  """
  vision_active = source == "Vision" and resolved_ms > 0.0
  if vision_active and (not _pulse["active"] or abs(resolved_ms - _pulse["last"]) >= VISION_SPEED_LIMIT_CHANGE_THRESHOLD):
    _pulse["start"] = rl.get_time()
  _pulse["active"] = vision_active
  _pulse["last"] = resolved_ms if vision_active else 0.0


def _speed_limit_pulse_color(base: rl.Color, alpha: int) -> rl.Color:
  """Blend ``base`` toward VISION_SPEED_LIMIT_PULSE_COLOR with a sin(pi*t) ease.

  Returns ``base`` unchanged (with the supplied alpha) outside the pulse
  window. Inside it, r/g/b are eased toward the pulse color along sin(pi*t)
  where t is elapsed / VISION_SPEED_LIMIT_PULSE_SECONDS.
  """
  base_with_alpha = rl.Color(base.r, base.g, base.b, alpha)
  elapsed = rl.get_time() - _pulse["start"]
  if elapsed < 0.0 or elapsed >= VISION_SPEED_LIMIT_PULSE_SECONDS:
    return base_with_alpha

  progress = elapsed / VISION_SPEED_LIMIT_PULSE_SECONDS
  pulse = math.sin(math.pi * progress)
  return rl.Color(
    round(base.r + (VISION_SPEED_LIMIT_PULSE_COLOR.r - base.r) * pulse),
    round(base.g + (VISION_SPEED_LIMIT_PULSE_COLOR.g - base.g) * pulse),
    round(base.b + (VISION_SPEED_LIMIT_PULSE_COLOR.b - base.b) * pulse),
    alpha,
  )


# ── State ─────────────────────────────────────────────────────────────

def _get_slc_state():
  """Extract SLC state from SubMaster. Returns dict or None if stale/hidden."""
  sm = ui_state.sm
  if sm.recv_frame["starpilotPlan"] < ui_state.started_frame:
    _reset_pulse()
    return None

  plan = sm["starpilotPlan"]
  speed_limit_changed = plan.speedLimitChanged

  params = ui_state.ui_params
  show_slc = params.get_bool("ShowSpeedLimits")
  unconfirmed_valid = plan.unconfirmedSlcSpeedLimit > 1

  if not show_slc:
    _reset_pulse()
    return None

  speed_conversion = CV.MS_TO_KPH if ui_state.is_metric else CV.MS_TO_MPH
  show_offset = params.get_bool("ShowSLCOffset")

  dashboard_sl = sm["starpilotCarState"].dashboardSpeedLimit if sm.valid.get("starpilotCarState", False) else 0.0
  vision_sl = ui_state.params_memory.get_float("VisionSpeedLimit") if params.get_bool("VisionSpeedLimitDetection") else 0.0

  slc_overridden_speed = plan.slcOverriddenSpeed
  # Driver override takes precedence over the planner's limit when active.
  speed_limit = slc_overridden_speed if slc_overridden_speed != 0 else plan.slcSpeedLimit

  # Resolved limit in m/s (pre-conversion, pre-offset) — feeds the vision pulse
  # change detector so the comparison is unit-stable across km/h ↔ mph flips.
  resolved_ms = speed_limit

  # Add the per-limit offset to the displayed value only when NOT overridden
  # AND ShowSLCOffset is off (when the offset toggle is on, it's rendered as
  # a separate field below the speed number instead).
  if slc_overridden_speed == 0 and not show_offset:
    speed_limit += plan.slcSpeedLimitOffset
  speed_limit *= speed_conversion

  speed_limit_offset = plan.slcSpeedLimitOffset * speed_conversion
  offset_str = f"{'+' if speed_limit_offset > 0 else '-'}{abs(int(round(speed_limit_offset)))}" if speed_limit_offset != 0 else "\u2013"

  # Update the vision-source pulse once per frame, after resolved_ms is known
  # and before any sign colors are computed downstream.
  _tick_pulse(plan.slcSpeedLimitSource, resolved_ms)

  return {
    'speed_limit': speed_limit,
    'speed_limit_str': "\u2013" if speed_limit <= 1 else str(int(round(speed_limit))),
    'slc_overridden_speed': slc_overridden_speed,
    'speed_limit_source': plan.slcSpeedLimitSource,
    'unconfirmed_speed_limit': max(0.0, plan.unconfirmedSlcSpeedLimit * speed_conversion),
    'unconfirmed_valid': unconfirmed_valid,
    'speed_limit_changed': speed_limit_changed,
    'show_offset': show_offset,
    'use_vienna': params.get_bool("UseVienna"),
    'offset_str': offset_str,
    'speed_conversion': speed_conversion,
    'speed_unit': " km/h" if ui_state.is_metric else " mph",
    # Per-source raw values
    'dashboard_sl': max(0.0, dashboard_sl * speed_conversion),
    'map_sl': max(0.0, plan.slcMapSpeedLimit * speed_conversion),
    'vision_sl': max(0.0, vision_sl * speed_conversion),
    'mapbox_sl': max(0.0, plan.slcMapboxSpeedLimit * speed_conversion),
    'next_sl': max(0.0, plan.slcNextSpeedLimit * speed_conversion),
  }


# ── Fonts ─────────────────────────────────────────────────────────────

_font_bold = None
_font_semi_bold = None

def _get_bold():
  global _font_bold
  if _font_bold is None:
    _font_bold = gui_app.font(FontWeight.BOLD)
  return _font_bold

def _get_semi_bold():
  global _font_semi_bold
  if _font_semi_bold is None:
    _font_semi_bold = gui_app.font(FontWeight.SEMI_BOLD)
  return _font_semi_bold


_ACTIVE_SOURCE_LABELS = {title: abbrev.upper() for title, abbrev, *_ in SOURCE_DEFS}


def _active_source_label(state: dict) -> str:
  source = state.get("speed_limit_source")
  if not source or source == "None":
    return tr("LIMIT")
  return _ACTIVE_SOURCE_LABELS.get(source, source.upper())


# ── US MUTCD Sign ─────────────────────────────────────────────────────

def _draw_offset_chip(rect: rl.Rectangle, offset_str: str, alpha: int) -> None:
  """Draw the optional SLC offset as a compact accent chip."""
  font = _get_semi_bold()
  text_size = measure_text_cached(font, offset_str, FONT_OFFSET)
  chip_w = max(64.0, text_size.x + 24.0)
  chip_h = 38.0
  chip_rect = rl.Rectangle(
    rect.x + (rect.width - chip_w) / 2,
    rect.y + rect.height - chip_h - 14,
    chip_w,
    chip_h,
  )
  chip_border = rl.Color(255, 255, 255, alpha)
  chip_fill = rl.Color(0, 0, 0, min(120, alpha))
  roundness = roundness_for(chip_rect, 18)
  rl.draw_rectangle_rounded(chip_rect, roundness, 12, chip_fill)
  rl.draw_rectangle_rounded_lines_ex(chip_rect, roundness, 12, 2, chip_border)
  rl.draw_text_ex(
    font,
    offset_str,
    rl.Vector2(chip_rect.x + (chip_w - text_size.x) / 2, chip_rect.y + (chip_h - text_size.y) / 2),
    FONT_OFFSET,
    0,
    chip_border,
  )


def _draw_us_sign(x: float, y: float, sign_width: float, sign_height: float,
                  speed_text: str, offset_str: str,
                  source_label: str, alpha: int, show_offset: bool, *, pending: bool = False):
  """Draw the NA control card at (x, y).

  The card keeps the SLC's label/value hierarchy while sharing the exact
  visible frame geometry with Set Speed. Border and text colors continue to
  use the existing Vision pulse and pending blink behavior.
  """
  # Pending: border blinks white <-> red. Active: border is white.
  if pending:
    blink_on = int(rl.get_time() * 1000) % 1000 < PENDING_BLINK_MS
    base_border = rl.Color(255, 255, 255, alpha) if blink_on else rl.Color(201, 34, 49, alpha)
  else:
    base_border = rl.Color(255, 255, 255, alpha)

  # Compose the blink base with the active vision pulse (no-op outside window).
  border_color = _speed_limit_pulse_color(base_border, alpha)
  # White value text reads on the translucent road background.
  text_color = _speed_limit_pulse_color(rl.Color(255, 255, 255, 255), alpha)

  card_rect = rl.Rectangle(x, y, sign_width, sign_height)
  card_fill = rl.Color(CONTROL_BG.r, CONTROL_BG.g, CONTROL_BG.b, min(CONTROL_BG.a, alpha))
  draw_control_card(card_rect, fill=card_fill, border=border_color,
                    border_width=CONTROL_BORDER_WIDTH)

  font_bold = _get_bold()
  font_semi = _get_semi_bold()
  cx = x + sign_width / 2

  # Pending layout: "PENDING" + "LIMIT" + speed (no offset shown when pending).
  if pending:
    pending_size = measure_text_cached(font_semi, tr("PENDING"), FONT_LABEL - 2)
    rl.draw_text_ex(font_semi, tr("PENDING"), rl.Vector2(cx - pending_size.x / 2, y + 20), FONT_LABEL - 2, 0, text_color)
    limit_size = measure_text_cached(font_semi, tr("LIMIT"), FONT_LABEL)
    rl.draw_text_ex(font_semi, tr("LIMIT"), rl.Vector2(cx - limit_size.x / 2, y + 48), FONT_LABEL, 0, text_color)
    speed_size = measure_text_cached(font_bold, speed_text, FONT_SPEED - 6)
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(cx - speed_size.x / 2, y + 85), FONT_SPEED - 6, 0, text_color)
  elif show_offset:
    # Offset ON: source at the top, speed below it, and the offset in a chip.
    source_size = measure_text_cached(font_semi, source_label, FONT_LABEL)
    source_color = _speed_limit_pulse_color(_WHITE, alpha)
    rl.draw_text_ex(font_semi, source_label, rl.Vector2(cx - source_size.x / 2, y + 20), FONT_LABEL, 0, source_color)

    speed_size = measure_text_cached(font_bold, speed_text, FONT_SPEED)
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(cx - speed_size.x / 2, y + 54), FONT_SPEED, 0, text_color)
    _draw_offset_chip(card_rect, offset_str, alpha)
  else:
    # Offset OFF: source at the top, speed centered in the remaining space.
    source_size = measure_text_cached(font_semi, source_label, FONT_LABEL)
    source_color = _speed_limit_pulse_color(_WHITE, alpha)
    rl.draw_text_ex(font_semi, source_label, rl.Vector2(cx - source_size.x / 2, y + 20), FONT_LABEL, 0, source_color)

    speed_size = measure_text_cached(font_bold, speed_text, FONT_SPEED)
    rl.draw_text_ex(font_bold, speed_text, rl.Vector2(cx - speed_size.x / 2, y + 78), FONT_SPEED, 0, text_color)


# ── EU Vienna Sign ────────────────────────────────────────────────────

def _draw_eu_sign(x: float, y: float, speed_text: str, offset_str: str,
                   source_label: str, text_alpha: int, show_offset: bool, *, pending: bool = False):
  """Draw EU-style (Vienna) speed limit sign at (x, y).

  White disk with a pulsable red ring and pulsable black text. The disk
  fill, ring, and text all carry the sign-wide ``text_alpha`` (e.g. 72 when
  driver-overridden, 255 otherwise), so the road shows through when dimmed
  without losing legibility. The pre-existing pending-text blink
  (black <-> red) composes with the vision pulse: outside the pulse window
  the blink is unchanged, inside it both colors are eased toward
  VISION_SPEED_LIMIT_PULSE_COLOR.
  """
  center_x = x + EU_SIGN_SIZE / 2
  center_y = y + EU_SIGN_SIZE / 2
  radius = EU_SIGN_SIZE / 2

  # White disk fill; alpha-dims with the sign so an overridden limit fades
  # against the road.
  rl.draw_circle(int(center_x), int(center_y), radius, rl.Color(255, 255, 255, text_alpha))
  # Red ring; eased toward VISION_SPEED_LIMIT_PULSE_COLOR when a Vision-sourced
  # limit just changed, and alpha-dims with the sign.
  ring_color = _speed_limit_pulse_color(rl.Color(201, 34, 49, 255), text_alpha)
  rl.draw_ring(rl.Vector2(center_x, center_y), radius - RED_RING_WIDTH, radius,
               0, 360, 64, ring_color)

  font_bold = _get_bold()

  eu_font = FONT_EU_LARGE if len(speed_text) <= 2 else FONT_EU_SMALL

  # EU pending: text blinks black/red, composed with the vision pulse.
  if pending:
    blink_on = int(rl.get_time() * 1000) % 1000 < PENDING_BLINK_MS
    base_text = rl.Color(0, 0, 0, 255) if blink_on else rl.Color(201, 34, 49, 255)
  else:
    base_text = rl.Color(0, 0, 0, 255)
  text_color = _speed_limit_pulse_color(base_text, text_alpha)

  # Pending: text centered (no offset display)
  if pending:
    speed_size = measure_text_cached(font_bold, speed_text, eu_font)
    speed_pos = rl.Vector2(center_x - speed_size.x / 2, center_y - speed_size.y / 2)
    rl.draw_text_ex(font_bold, speed_text, speed_pos, eu_font, 0, text_color)
  elif not show_offset:
    font_semi = _get_semi_bold()
    source_size = measure_text_cached(font_semi, source_label, FONT_LABEL - 4)
    source_pos = rl.Vector2(center_x - source_size.x / 2, y + 16)
    rl.draw_text_ex(font_semi, source_label, source_pos, FONT_LABEL - 4, 0, text_color)

    speed_size = measure_text_cached(font_bold, speed_text, eu_font)
    speed_pos = rl.Vector2(center_x - speed_size.x / 2, center_y - speed_size.y / 2)
    rl.draw_text_ex(font_bold, speed_text, speed_pos, eu_font, 0, text_color)
  else:
    # Offset ON: source at the top, speed below it, offset at the bottom.
    font_semi = _get_semi_bold()
    source_size = measure_text_cached(font_semi, source_label, FONT_LABEL - 4)
    source_pos = rl.Vector2(center_x - source_size.x / 2, y + 16)
    rl.draw_text_ex(font_semi, source_label, source_pos, FONT_LABEL - 4, 0, text_color)

    speed_size = measure_text_cached(font_bold, speed_text, eu_font)
    speed_pos = rl.Vector2(center_x - speed_size.x / 2, center_y - speed_size.y / 2 - 5)
    rl.draw_text_ex(font_bold, speed_text, speed_pos, eu_font, 0, text_color)

    offset_size = measure_text_cached(font_semi, offset_str, FONT_EU_OFFSET)
    offset_pos = rl.Vector2(center_x - offset_size.x / 2, y + 122)
    rl.draw_text_ex(font_semi, offset_str, offset_pos, FONT_EU_OFFSET, 0, text_color)


# ── Dispatcher (pending and active sign share the same rect) ─────────

def _draw_sign(state: dict, rect: rl.Rectangle, *, pending: bool = False):
  """Draw either the pending or active sign in the given rect."""
  if pending:
    # Pending shows the unconfirmed value, full opacity
    speed_text = ("\u2013" if state['unconfirmed_speed_limit'] <= 1
                  else str(int(round(state['unconfirmed_speed_limit']))))
    text_alpha = 255
  else:
    speed_text = state['speed_limit_str']
    # Override dim: when the driver has manually overridden the speed limit,
    # fade the sign to alpha=72 to indicate it's no longer the auto-detected
    # value.
    text_alpha = 72 if state['slc_overridden_speed'] != 0 else 255

  source_label = _active_source_label(state)

  if state['use_vienna']:
    _draw_eu_sign(rect.x, rect.y, speed_text, state['offset_str'], source_label, text_alpha,
                   state['show_offset'], pending=pending)
  else:
    _draw_us_sign(rect.x, rect.y, rect.width, rect.height, speed_text, state['offset_str'],
                   source_label, text_alpha, state['show_offset'], pending=pending)


# ── Sources Bubble (expandable overlay) ────────────────────────────────

_SOURCE_PANEL_WIDTH = 300
_SOURCE_PANEL_GAP = 28
_SOURCE_PANEL_PAD_X = 18
_SOURCE_PANEL_PAD_Y = 4
_SOURCE_PANEL_BG = rl.Color(0, 0, 0, 145)
_SOURCE_DIVIDER = rl.Color(196, 205, 208, 70)
_SOURCE_ICON_MUTED = rl.Color(196, 205, 208, 190)
_SOURCE_LABEL = rl.Color(255, 255, 255, 215)
_SOURCE_FONT = 34
_SOURCE_MIN_FONT = 22
_SOURCE_TEXT_GAP = 12
_SOURCE_ICON_SIZE = 30


def _fit_sources_row(font, label: str, value_text: str, row_h: float, available_w: float):
  font_size = min(_SOURCE_FONT, max(_SOURCE_MIN_FONT, int(row_h * 0.82)))
  label_size = measure_text_cached(font, label, font_size)
  value_size = measure_text_cached(font, value_text, font_size)
  needed_w = label_size.x + value_size.x + _SOURCE_TEXT_GAP

  if needed_w > available_w:
    font_size = max(_SOURCE_MIN_FONT, int(font_size * (available_w / needed_w)))
    label_size = measure_text_cached(font, label, font_size)
    value_size = measure_text_cached(font, value_text, font_size)
    while label_size.x + value_size.x + _SOURCE_TEXT_GAP > available_w and font_size > _SOURCE_MIN_FONT:
      font_size -= 1
      label_size = measure_text_cached(font, label, font_size)
      value_size = measure_text_cached(font, value_text, font_size)

  fits = label_size.x + value_size.x + _SOURCE_TEXT_GAP <= available_w
  return font_size, value_size, fits


def _draw_source_icon(icon_key: str, x: float, y: float, size: float, color: rl.Color) -> None:
  """Draw the small, intentionally simple source glyphs used by the panel."""
  cx = x + size / 2
  cy = y + size / 2
  stroke = max(2.0, size / 12.0)

  if icon_key == "map":
    left = x + size * 0.12
    right = x + size * 0.88
    top = y + size * 0.18
    bottom = y + size * 0.82
    fold = size * 0.25
    rl.draw_line_ex(rl.Vector2(left, top), rl.Vector2(left, bottom), stroke, color)
    rl.draw_line_ex(rl.Vector2(left, top), rl.Vector2(left + fold, top + size * 0.12), stroke, color)
    rl.draw_line_ex(rl.Vector2(left + fold, top + size * 0.12), rl.Vector2(left + fold, bottom + size * 0.12), stroke, color)
    rl.draw_line_ex(rl.Vector2(left + fold, top + size * 0.12), rl.Vector2(left + fold * 2.0, top), stroke, color)
    rl.draw_line_ex(rl.Vector2(left + fold * 2.0, top), rl.Vector2(left + fold * 2.0, bottom), stroke, color)
    rl.draw_line_ex(rl.Vector2(left + fold * 2.0, top), rl.Vector2(right, top + size * 0.12), stroke, color)
    rl.draw_line_ex(rl.Vector2(right, top + size * 0.12), rl.Vector2(right, bottom + size * 0.12), stroke, color)
  elif icon_key == "camera":
    body = rl.Rectangle(x + size * 0.08, y + size * 0.28, size * 0.84, size * 0.54)
    rl.draw_rectangle_rounded(body, 0.25, 8, color)
    lens = rl.Vector2(cx, y + size * 0.55)
    rl.draw_circle_v(lens, size * 0.17, _SOURCE_PANEL_BG)
    rl.draw_circle_lines(int(lens.x), int(lens.y), size * 0.17, color)
    rl.draw_rectangle_rounded(
      rl.Rectangle(x + size * 0.28, y + size * 0.16, size * 0.24, size * 0.17),
      0.25, 6, color,
    )
  elif icon_key == "navigation":
    head = rl.Vector2(x + size * 0.82, y + size * 0.16)
    left = rl.Vector2(x + size * 0.16, y + size * 0.78)
    right = rl.Vector2(x + size * 0.64, y + size * 0.84)
    rl.draw_triangle(left, head, right, color)
    rl.draw_line_ex(left, head, stroke, color)
    rl.draw_line_ex(head, right, stroke, color)
  else:  # Dashboard / fallback
    rl.draw_ring(rl.Vector2(cx, cy + size * 0.10), size * 0.27, size * 0.34, 200, 340, 24, color)
    rl.draw_line_ex(
      rl.Vector2(cx, cy + size * 0.10),
      rl.Vector2(cx + size * 0.18, cy - size * 0.12),
      stroke,
      color,
    )
    rl.draw_circle_v(rl.Vector2(cx, cy + size * 0.10), stroke, color)


def _draw_sources_bubble(state: dict, sign_rect: rl.Rectangle):
  """Draw the expanded source list attached to the SLC card."""
  font_bold = _get_bold()
  font_semi = _get_semi_bold()
  active_source = state['speed_limit_source']

  rows = []
  for title, abbrev, value_key, panel_label, icon_key in SOURCE_DEFS:
    value = state[value_key]
    if value == 0:
      continue
    rows.append((title, abbrev, panel_label, icon_key, value, active_source == title))

  if not rows:
    return

  panel_rect = rl.Rectangle(
    sign_rect.x + sign_rect.width + _SOURCE_PANEL_GAP,
    sign_rect.y,
    _SOURCE_PANEL_WIDTH,
    sign_rect.height,
  )
  rl.draw_rectangle_rounded(panel_rect, roundness_for(panel_rect), 16, _SOURCE_PANEL_BG)

  row_h = (panel_rect.height - 2 * _SOURCE_PANEL_PAD_Y) / len(rows)
  content_left = panel_rect.x + _SOURCE_PANEL_PAD_X
  content_right = panel_rect.x + panel_rect.width - _SOURCE_PANEL_PAD_X
  label_left = content_left + _SOURCE_ICON_SIZE + _SOURCE_TEXT_GAP
  available_w = content_right - label_left

  for index, (title, abbrev, panel_label, icon_key, value, is_active) in enumerate(rows):
    row_y = panel_rect.y + _SOURCE_PANEL_PAD_Y + index * row_h
    if index:
      divider_y = row_y
      rl.draw_line_ex(
        rl.Vector2(content_left, divider_y),
        rl.Vector2(content_right, divider_y),
        1,
        _SOURCE_DIVIDER,
      )

    text_font = font_bold if is_active else font_semi
    label_text = panel_label
    value_text = str(int(round(value)))
    font_size, value_size, fits = _fit_sources_row(
      text_font, label_text, value_text, row_h, available_w
    )
    if not fits:
      label_text = abbrev
      font_size, value_size, _ = _fit_sources_row(
        text_font, label_text, value_text, row_h, available_w
      )

    baseline_y = row_y + (row_h - font_size) / 2
    icon_y = row_y + (row_h - _SOURCE_ICON_SIZE) / 2
    icon_color = _WHITE if is_active else _SOURCE_ICON_MUTED
    _draw_source_icon(icon_key, content_left, icon_y, _SOURCE_ICON_SIZE, icon_color)

    label_pos = rl.Vector2(label_left, baseline_y)
    value_pos = rl.Vector2(content_right - value_size.x, baseline_y)
    label_color = _SOURCE_LABEL
    value_color = _WHITE if is_active else _SOURCE_LABEL
    rl.draw_text_ex(text_font, label_text, label_pos, font_size, 0, label_color)
    rl.draw_text_ex(text_font, value_text, value_pos, font_size, 0, value_color)


# ── Public API ────────────────────────────────────────────────────────

def render_speed_limit_at(state: dict, rect: rl.Rectangle, expanded: bool = False) -> Optional[rl.Rectangle]:
  """Render the SLC sign and optional source bubble at a layout rect."""
  flashing_pending = state['speed_limit_changed'] and state['unconfirmed_valid']

  if flashing_pending:
    _draw_sign(state, rect, pending=True)
    return None

  _draw_sign(state, rect, pending=False)

  use_vienna = state['use_vienna']
  visual_rect = rl.Rectangle(rect.x, rect.y, EU_SIGN_SIZE, EU_SIGN_SIZE) if use_vienna else rect

  source = state.get('speed_limit_source')
  if expanded and source and source != "None" and source != "":
    _draw_sources_bubble(state, visual_rect)

  return visual_rect
