"""Covers assets/components/recordings/dashcam_routes_helpers.js.

The helpers are browser ES modules, so pytest drives them through node rather than
re-implementing the date/sort/grouping rules in Python. Snippets run with helper
exports in scope and return JSON, which keeps every assertion here in pytest.
"""

import json
import os
from pathlib import Path
import shutil
import subprocess

import pytest

HELPERS_PATH = Path(__file__).resolve().parent.parent / "assets" / "components" / "recordings" / "dashcam_routes_helpers.js"

# node infers ESM from `export` syntax in a bare .js file from 22.7 on, so the helpers
# need no package.json and stay a normal asset next to the component that imports them.
MIN_NODE_MAJOR = 23

HARNESS = f'''
import * as helpers from {json.dumps(HELPERS_PATH.as_uri())}
const run = new Function(...Object.keys(helpers), process.env.DASHCAM_HELPER_SNIPPET)
process.stdout.write(JSON.stringify(run(...Object.values(helpers)) ?? null))
'''

PRELUDE = '''
const route = (name, startedAt, extra = {}) => normalizeRoute({
  name,
  startedAt,
  timestamp: startedAt,
  segmentCount: 1,
  approxDurationSeconds: 60,
  is_preserved: false,
  ...extra,
}, "en-US")
'''


def _node_binary():
  node = shutil.which("node")
  if node is None:
    pytest.skip("node is not installed")

  version = subprocess.run([node, "--version"], capture_output=True, text=True, timeout=30).stdout.strip()
  try:
    major = int(version.lstrip("v").split(".")[0])
  except ValueError:
    pytest.skip(f"could not read node version from {version!r}")
  if major < MIN_NODE_MAJOR:
    pytest.skip(f"node {version} cannot import a bare .js ES module; need v{MIN_NODE_MAJOR}+")
  return node


def evaluate(snippet):
  """Run a snippet with the helper exports in scope and return its JSON value."""
  node = _node_binary()
  # Fixed TZ so "Today"/"Yesterday" grouping does not depend on the developer's clock.
  environment = {**os.environ, "TZ": "UTC", "DASHCAM_HELPER_SNIPPET": PRELUDE + snippet}
  result = subprocess.run([node, "--input-type=module"], input=HARNESS, env=environment,
                          capture_output=True, text=True, timeout=60)
  assert result.returncode == 0, result.stderr
  return json.loads(result.stdout)


def test_helpers_module_is_a_plain_js_asset():
  assert HELPERS_PATH.is_file()
  assert not list(HELPERS_PATH.parent.glob("*.mjs"))


def test_groups_routes_into_today_yesterday_dates_and_unknown():
  groups = evaluate('''
    const routes = [
      route("today", "2026-08-26T08:00:00Z"),
      route("yesterday", "2026-08-25T08:00:00Z"),
      route("older", "2026-08-20T08:00:00Z"),
      route("unknown", null, { timestamp: null }),
    ]
    return groupRoutesByDate(routes, new Date("2026-08-26T12:00:00Z"), "en-US")
      .map(group => [group.label, group.routes[0].name])
  ''')

  assert groups == [
    ["Today", "today"],
    ["Yesterday", "yesterday"],
    ["August 20, 2026", "older"],
    ["Unknown date", "unknown"],
  ]


def test_sorts_newest_and_oldest_while_leaving_unknown_dates_last():
  order = evaluate('''
    const routes = [
      route("middle", "2026-08-20T08:00:00Z"),
      route("unknown", null, { timestamp: null }),
      route("new", "2026-08-26T08:00:00Z"),
      route("old", "2026-08-10T08:00:00Z"),
    ]
    return {
      newest: sortRoutes(routes, "newest").map(item => item.name),
      oldest: sortRoutes(routes, "oldest").map(item => item.name),
    }
  ''')

  assert order["newest"] == ["new", "middle", "old", "unknown"]
  assert order["oldest"] == ["old", "middle", "new", "unknown"]


def test_searches_custom_names_displayed_dates_and_route_ids():
  matches = evaluate('''
    const custom = route("0000006a--9f0a7bdf9c", "2026-08-26T08:00:00Z", {
      timestamp: "Morning school run",
      isCustomName: true,
    })
    return ["school", "August 26", "9f0a7b", "evening"]
      .map(searchQuery => buildRouteView([custom], { searchQuery }).matching.length)
  ''')

  assert matches == [1, 1, 1, 0]


def test_filters_preserved_routes_before_applying_the_render_limit():
  view = evaluate('''
    const routes = Array.from({ length: MAX_RENDERED_ROUTES + 25 }, (_, index) => route(
      `route-${index}`,
      new Date(Date.UTC(2026, 0, 1, 0, index)).toISOString(),
      { is_preserved: index % 2 === 0 },
    ))
    const all = buildRouteView(routes)
    const preserved = buildRouteView(routes, { preservedOnly: true })
    return {
      limit: MAX_RENDERED_ROUTES,
      all: [all.matching.length, all.visible.length, all.truncated],
      preserved: [preserved.matching.length, preserved.visible.length, preserved.truncated],
      allPreserved: preserved.visible.every(item => item.is_preserved),
    }
  ''')

  assert view["limit"] == 250
  assert view["all"] == [275, 250, True]
  assert view["preserved"] == [138, 138, False]
  assert view["allPreserved"] is True


def test_segment_status_uses_stored_sparse_numbers_and_playback_position():
  statuses = evaluate('''
    const segments = [
      "/video/0000006a--9f0a7bdf9c--0",
      "/video/0000006a--9f0a7bdf9c--3",
      "/video/0000006a--9f0a7bdf9c--11",
    ]
    return segments.map((_, index) => getSegmentStatus(segments, index))
  ''')

  assert statuses == [
    "Segment 0 · 1 of 3",
    "Segment 3 · 2 of 3",
    "Segment 11 · 3 of 3",
  ]


def test_hides_segment_status_when_the_stored_number_is_unsafe():
  results = evaluate('''
    return [
      parseStoredSegmentNumber("/video/route--9007199254740992"),
      getSegmentStatus(["/video/not-a-segment"], 0),
      getSegmentStatus(undefined, 0),
    ]
  ''')

  assert results == [None, "", ""]


def test_switching_camera_changes_only_the_url_and_not_segment_status():
  result = evaluate('''
    const segments = ["/video/0000006a--9f0a7bdf9c--7"]
    const before = getSegmentStatus(segments, 0)
    return {
      url: cameraVideoUrl(segments[0], "driver"),
      unchanged: getSegmentStatus(segments, 0) === before,
    }
  ''')

  assert result["url"] == "/video/0000006a--9f0a7bdf9c--7?camera=driver"
  assert result["unchanged"] is True
