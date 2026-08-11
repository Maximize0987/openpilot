# ui

The user interfaces here are built with [raylib](https://www.raylib.com/).

Quick start:
* set `BIG=1` to run the comma 3X UI (comma four UI runs by default)
* set `SHOW_FPS=1` to show the FPS
* set `STRICT_MODE=1` to kill the app if it drops too much below 60fps
* set `SCALE=1.5` to scale the entire UI by 1.5x
* set `BURN_IN=1` to get a burn-in heatmap version of the UI
* burn-in prevention shifts the UI by 2 pixels every 3 minutes on device; set `BURN_IN_PREVENTION=0` to disable it
  or tune it with `BURN_IN_SHIFT_PIXELS` and `BURN_IN_SHIFT_INTERVAL` (seconds); on TICI/TIZI, near-white pixels are also softly capped
  at 95% luminance and can be tuned or disabled with `WHITE_LUMINANCE_CAP` (set it to `1.0` to disable). MICI uses direct shifting
  by default, while enabling a luminance cap or forced render texture opts it into the offscreen path.
* set `MICI_FORCE_RENDER_TEXTURE=1` to force the C4 UI through the offscreen presentation path for diagnostics
* set `GRID=50` to show a 50-pixel alignment grid overlay
* set `MAGIC_DEBUG=1` to show every dropped frames (only on device)
* set `RECORD=1` to record the screen, output defaults to `output.mp4` but can be set with `RECORD_OUTPUT`
* https://www.raylib.com/cheatsheet/cheatsheet.html
* https://electronstudio.github.io/raylib-python-cffi/README.html#quickstart

Style guide:
* All graphical elements should subclass [`Widget`](/system/ui/widgets/__init__.py).
  * Prefer a stateful widget over a function for easy migration from QT
* All internal class variables and functions should be prefixed with `_`
