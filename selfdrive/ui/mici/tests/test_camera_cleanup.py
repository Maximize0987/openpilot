import gc
from types import SimpleNamespace
import weakref

import pytest

from openpilot.selfdrive.ui.mici.onroad import cameraview as mici_cameraview
from openpilot.selfdrive.ui.onroad import cameraview as big_cameraview


@pytest.mark.parametrize("module", (mici_cameraview, big_cameraview))
def test_road_transition_releases_camera_buffers(monkeypatch, module):
  class FakeClient:
    pass

  view = module.CameraView.__new__(module.CameraView)
  old_client = FakeClient()
  old_client_ref = weakref.ref(old_client)
  view._name = "camerad"
  view._stream_type = object()
  view.client = old_client
  view.frame = None
  view.available_streams = [object()]
  view._target_client = FakeClient()
  view._target_stream_type = object()
  view._switching = True
  view._texture_needs_update = False
  view.last_connection_attempt = 123.0
  view._closed = True
  cleared = []
  view._clear_textures = lambda: cleared.append(True)

  monkeypatch.setattr(module, "VisionIpcClient", lambda *_args, **_kwargs: FakeClient())
  del old_client

  view._offroad_transition()
  gc.collect()

  assert old_client_ref() is None
  assert cleared == [True]
  assert view.frame is None
  assert view.available_streams == []
  assert view._target_client is None
  assert view._target_stream_type is None
  assert view._switching is False
  assert view._texture_needs_update
  assert view.last_connection_attempt == 0.0


@pytest.mark.parametrize("module", (mici_cameraview, big_cameraview))
def test_transition_callback_does_not_retain_camera_view(monkeypatch, module):
  class FakeClient:
    pass

  callbacks = []
  monkeypatch.setattr(module, "TICI", False)
  monkeypatch.setattr(module, "VisionIpcClient", lambda *_args, **_kwargs: FakeClient())
  monkeypatch.setattr(module.rl, "load_shader_from_memory", lambda *_args: SimpleNamespace(id=1))
  monkeypatch.setattr(module.rl, "get_shader_location", lambda *_args: 0)
  monkeypatch.setattr(module.rl, "unload_shader", lambda *_args: None)
  monkeypatch.setattr(module.ui_state, "add_offroad_transition_callback", callbacks.append)
  monkeypatch.setattr(module.ui_state, "remove_offroad_transition_callback", callbacks.remove)

  view = module.CameraView("camerad", object())
  view_ref = weakref.ref(view)
  assert len(callbacks) == 1

  del view
  gc.collect()

  assert view_ref() is None
  assert callbacks == []


@pytest.mark.parametrize("module", (mici_cameraview, big_cameraview))
def test_stream_switch_releases_graphics_before_old_client(module):
  events = []

  class FakeClient:
    pass

  view = module.CameraView.__new__(module.CameraView)
  view.client = FakeClient()
  old_client_finalizer = weakref.finalize(view.client, events.append, "client")
  view._target_client = FakeClient()
  view._target_stream_type = object()
  view._stream_type = object()
  view._switching = True
  view._texture_needs_update = False
  view._closed = True
  view._clear_textures = lambda: events.append("graphics")
  view._initialize_textures = lambda: events.append("initialize")

  view._complete_switch()
  gc.collect()

  assert old_client_finalizer.alive is False
  assert events == ["graphics", "client", "initialize"]


@pytest.mark.parametrize(("target_stream", "expected"), (
  (mici_cameraview.VisionStreamType.VISION_STREAM_DRIVER, 1),
  (mici_cameraview.VisionStreamType.VISION_STREAM_ROAD, 0),
  (mici_cameraview.VisionStreamType.VISION_STREAM_WIDE_ROAD, 0),
))
def test_mici_stream_switch_updates_driver_enhancement(target_stream, expected):
  class FakeClient:
    frame_id = 42

  view = mici_cameraview.CameraView.__new__(mici_cameraview.CameraView)
  view.client = FakeClient()
  view._target_client = FakeClient()
  view._target_stream_type = target_stream
  view._stream_type = mici_cameraview.VisionStreamType.VISION_STREAM_DRIVER
  view._switching = True
  view._texture_needs_update = False
  view._enhance_driver_val = [-1]
  view._closed = True
  view._clear_textures = lambda: None
  view._initialize_textures = lambda: None

  view._complete_switch()

  assert view._enhance_driver_val[0] == expected
  assert view._last_frame_id == -1


@pytest.mark.parametrize("module", (mici_cameraview, big_cameraview))
def test_egl_cleanup_deletes_texture_before_images(monkeypatch, module):
  events = []
  view = module.CameraView.__new__(module.CameraView)
  view.texture_y = None
  view.texture_uv = None
  view.egl_texture = SimpleNamespace(id=7)
  view._external_texture_id = 11
  view.egl_images = {0: object(), 1: object()}
  view._closed = True

  if module is mici_cameraview:
    view._use_egl = True
  else:
    monkeypatch.setattr(module, "TICI", True)

  monkeypatch.setattr(module.rl, "unload_texture", lambda _texture: events.append("texture"))
  monkeypatch.setattr(module, "destroy_external_texture", lambda _texture: events.append("external"))
  monkeypatch.setattr(module, "destroy_egl_image", lambda _image: events.append("image"))

  view._clear_textures()

  assert events == ["external", "texture", "image", "image"]
  assert view.egl_texture is None
  assert view._external_texture_id == 0
  assert view.egl_images == {}


@pytest.mark.parametrize("module", (mici_cameraview, big_cameraview))
def test_egl_render_keeps_external_and_raylib_texture_targets_separate(monkeypatch, module):
  frame = SimpleNamespace(idx=3, width=1928, height=1208, stride=2048, fd=9, uv_offset=2473984)
  image = object()
  view = module.CameraView.__new__(module.CameraView)
  view.frame = frame
  view.egl_texture = SimpleNamespace(id=7, width=1, height=1)
  view._external_texture_id = 11
  view.egl_images = {frame.idx: image}
  view.shader = object()
  view._closed = True
  view._update_texture_color_filtering = lambda: None

  bound = []
  drawn = []
  monkeypatch.setattr(module, "bind_egl_image_to_texture", lambda texture_id, egl_image: bound.append((texture_id, egl_image)))
  monkeypatch.setattr(module.rl, "begin_shader_mode", lambda _shader: None)
  monkeypatch.setattr(module.rl, "end_shader_mode", lambda: None)
  monkeypatch.setattr(module.rl, "draw_texture_pro", lambda texture, *_args: drawn.append(texture.id))

  rect = SimpleNamespace()
  view._render_egl(rect, rect)

  assert bound == [(11, image)]
  assert drawn == [7]
