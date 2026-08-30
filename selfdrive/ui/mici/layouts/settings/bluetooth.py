import pyray as rl

from openpilot.selfdrive.ui.mici.layouts.settings.network.wifi_ui import ForgetButton, LoadingAnimation
from openpilot.selfdrive.ui.mici.widgets.button import BigButton, LABEL_COLOR
from openpilot.selfdrive.ui.mici.widgets.dialog import BigConfirmationDialog, BigDialog, BigInputDialog, BigMultiOptionDialog
from openpilot.system.ui.lib.application import FontWeight, MousePos, gui_app
from openpilot.system.ui.lib.bluetooth_manager import BluetoothManager
from openpilot.system.ui.widgets.scroller import NavScroller


class BluetoothDeviceButton(BigButton):
  LABEL_PADDING = 98
  LABEL_WIDTH = 402 - 98 - 28
  SUB_LABEL_WIDTH = 402 - BigButton.LABEL_HORIZONTAL_PADDING * 2

  def __init__(self, device, manager: BluetoothManager, icon: rl.Texture, selected_audio: str, offroad: bool):
    super().__init__(device.name, "", scroll=True)
    self.device = device
    self._manager = manager
    self._icon = icon
    self._offroad = offroad
    self._selected_audio = selected_audio
    self._check_txt = gui_app.texture("icons_mici/setup/driver_monitoring/dm_check.png", 32, 32)
    self._forget_btn = ForgetButton(lambda: self._manager.forget(self.device.address))
    self.update_device(device, selected_audio, offroad)

  def _get_label_font_size(self):
    return 48

  @property
  def _show_forget_btn(self):
    return self.device.paired and self._offroad

  def update_device(self, device, selected_audio: str, offroad: bool):
    self.device = device
    self._selected_audio = selected_audio
    self._offroad = offroad
    states = ["connected" if device.connected else "paired" if device.paired else "pair"]
    if device.audio:
      states.append("audio selected" if selected_audio.upper() == device.address.upper() else "audio")
    if device.controller:
      states.append("controller")
    self.set_value(" / ".join(states))

  def _handle_mouse_release(self, mouse_pos: MousePos):
    if self._show_forget_btn and rl.check_collision_point_rec(mouse_pos, self._forget_btn.rect):
      return
    super()._handle_mouse_release(mouse_pos)

  def set_touch_valid_callback(self, touch_callback):
    super().set_touch_valid_callback(lambda: touch_callback() and not self._forget_btn.is_pressed)
    self._forget_btn.set_touch_valid_callback(touch_callback)

  def _draw_content(self, btn_y: float):
    self._label.set_color(LABEL_COLOR)
    label_rect = rl.Rectangle(self._rect.x + self.LABEL_PADDING, btn_y + self.LABEL_VERTICAL_PADDING,
                              self.LABEL_WIDTH, self._rect.height - self.LABEL_VERTICAL_PADDING * 2)
    self._label.render(label_rect)

    sub_label_x = self._rect.x + self.LABEL_HORIZONTAL_PADDING
    label_y = btn_y + self._rect.height - self.LABEL_VERTICAL_PADDING
    sub_label_w = self.SUB_LABEL_WIDTH - (self._forget_btn.rect.width if self._show_forget_btn else 0)
    sub_label_height = self._sub_label.get_content_height(sub_label_w)
    if self.device.connected:
      check_y = int(label_y - sub_label_height + (sub_label_height - self._check_txt.height) / 2)
      rl.draw_texture_ex(self._check_txt, rl.Vector2(sub_label_x, check_y), 0.0, 1.0,
                         rl.Color(255, 255, 255, int(255 * 0.585)))
      sub_label_x += self._check_txt.width + 14
    self._sub_label.set_color(rl.Color(255, 255, 255, int(255 * 0.9)))
    self._sub_label.set_font_weight(FontWeight.SEMI_BOLD)
    self._sub_label.render(rl.Rectangle(sub_label_x, label_y - sub_label_height, sub_label_w, sub_label_height))

    rl.draw_texture_ex(self._icon, (self._rect.x + 30, btn_y + 30), 0.0, 1.0, rl.WHITE)
    if self._show_forget_btn:
      self._forget_btn.render(rl.Rectangle(
        self._rect.x + self._rect.width - self._forget_btn.rect.width,
        btn_y + self._rect.height - self._forget_btn.rect.height,
        self._forget_btn.rect.width,
        self._forget_btn.rect.height,
      ))


class BluetoothScanningButton(BigButton):
  def __init__(self):
    super().__init__("", "searching for devices")
    self.set_enabled(False)
    self._loading_animation = LoadingAnimation()

  def _draw_content(self, btn_y: float):
    super()._draw_content(btn_y)
    animation = self._loading_animation
    animation.set_position(self._rect.x + self._rect.width - animation.rect.width - 40,
                           btn_y + self._rect.height - animation.rect.height - 30)
    animation.render()


class BluetoothAudioTestDialog(BigDialog):
  def __init__(self, manager: BluetoothManager, icon: rl.Texture):
    super().__init__("starting", "The test sound is sent at NOW", icon)
    self._manager = manager

  def _render(self, rect):
    self._card.set_text(self._manager.audio_test_phase())
    super()._render(rect)


class BluetoothLayoutMici(NavScroller):
  def __init__(self):
    super().__init__()
    self._manager = BluetoothManager()
    self._last_signature = None
    self._last_prompt_id = ""
    self._bluetooth_icon = gui_app.texture("icons_mici/settings/bluetooth.png", 56, 56)
    self._dialog_icon = gui_app.texture("icons_mici/settings/bluetooth.png", 64, 64)
    self._power_btn = BigButton("bluetooth", "off", self._dialog_icon, scroll=True)
    self._power_btn.set_click_callback(self._toggle_power)
    self._scan_btn = BigButton("scan for devices", "scan", self._dialog_icon, scroll=True)
    self._scan_btn.set_click_callback(lambda: self._manager.set_scanning(True))
    self._scanning_btn = BluetoothScanningButton()
    self._rebuild()

  def show_event(self):
    super().show_event()
    self._manager.set_active(True)
    gui_app.add_nav_stack_tick(self._tick)

  def hide_event(self):
    self._manager.set_active(False)
    gui_app.remove_nav_stack_tick(self._tick)
    super().hide_event()

  def _toggle_power(self):
    self._manager.set_power(not self._manager.status.enabled)

  def _rebuild(self):
    status = self._manager.status
    self._power_btn.set_value("on" if status.enabled else "off")
    self._power_btn.set_enabled(status.available and status.offroad)
    self._scan_btn.set_enabled(status.enabled and status.offroad)
    items = [self._power_btn]
    for device in status.devices:
      button = BluetoothDeviceButton(device, self._manager, self._bluetooth_icon, status.selected_audio, status.offroad)
      button.set_enabled(status.offroad or device.paired)
      button.set_click_callback(lambda selected=device: self._device_actions(selected))
      items.append(button)
    if status.enabled:
      items.append(self._scanning_btn if status.discovering else self._scan_btn)
    self._scroller.items.clear()
    self._scroller.add_widgets(items)

  def _device_actions(self, device):
    if not device.paired:
      self._manager.pair(device.address)
      return

    options = ["disconnect" if device.connected else "connect"]
    if device.audio:
      selected = self._manager.status.selected_audio.upper() == device.address.upper()
      options.append("stop using for audio" if selected else "use for audio")
      if device.connected and self._manager.status.offroad:
        options.append("test audio")
    if self._manager.status.offroad:
      options.append("forget")
    dialog_holder = {}

    def apply():
      action = dialog_holder["dialog"].get_selected_option()
      if action == "connect":
        self._manager.connect(device.address)
      elif action == "disconnect":
        self._manager.disconnect(device.address)
      elif action == "use for audio":
        self._manager.select_audio(device.address)
      elif action == "stop using for audio":
        self._manager.select_audio("")
      elif action == "test audio":
        self._manager.test_audio(device.address)
        gui_app.push_widget(BluetoothAudioTestDialog(self._manager, self._dialog_icon))
      elif action == "forget":
        self._manager.forget(device.address)

    dialog = BigMultiOptionDialog(options=options, default=options[0], right_btn_callback=apply)
    dialog_holder["dialog"] = dialog
    gui_app.push_widget(dialog)

  def _handle_prompt(self):
    prompt = self._manager.status.prompt
    if prompt is None or prompt.get("id") == self._last_prompt_id:
      return
    self._last_prompt_id = prompt["id"]
    name = prompt.get("name") or "Bluetooth device"
    value = str(prompt.get("value") or "")
    if prompt.get("display_only"):
      gui_app.push_widget(BigDialog(name, value))
    elif prompt.get("kind") in ("pin", "passkey"):
      gui_app.push_widget(BigInputDialog(
        f"enter {prompt['kind']} for {name}",
        minimum_length=1,
        confirm_callback=lambda response: self._manager.respond(prompt["id"], True, response),
      ))
    else:
      title = f"slide to pair\n{name}"
      if value:
        title += f"\n{value}"
      gui_app.push_widget(BigConfirmationDialog(
        title,
        self._dialog_icon,
        lambda: self._manager.respond(prompt["id"], True),
      ))

  def _tick(self):
    status = self._manager.status
    signature = (
      status.available,
      status.enabled,
      status.powered,
      status.discovering,
      status.offroad,
      status.selected_audio,
      tuple((device.address, device.name, device.paired, device.connected, device.audio, device.controller) for device in status.devices),
    )
    if signature != self._last_signature:
      self._last_signature = signature
      self._rebuild()
    error = self._manager.consume_error()
    if error:
      gui_app.push_widget(BigDialog("Bluetooth", error))
    self._handle_prompt()
