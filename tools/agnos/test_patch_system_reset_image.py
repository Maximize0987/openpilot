import importlib.util
import json
from pathlib import Path

import pytest


def _load_patch_module():
  path = Path(__file__).resolve().parent / "patch_system_reset_image.py"
  spec = importlib.util.spec_from_file_location("patch_system_reset_image_under_test", path)
  module = importlib.util.module_from_spec(spec)
  spec.loader.exec_module(module)
  return module


patch_image = _load_patch_module()
ALLOWED_IMAGE_MUTATIONS = patch_image.ALLOWED_IMAGE_MUTATIONS
UPSTREAM_PROTECTED_PAYLOADS = patch_image.UPSTREAM_PROTECTED_PAYLOADS
VERSION_PATH_IN_IMAGE = patch_image.VERSION_PATH_IN_IMAGE
resolve_upstream_manifest = patch_image.resolve_upstream_manifest
update_manifest_system_entry = patch_image.update_manifest_system_entry
write_allowed_file = patch_image.write_allowed_file
expected_upstream_version = patch_image.expected_upstream_version
verify_official_raw_hash = patch_image.verify_official_raw_hash


def test_only_version_is_mutable():
  assert ALLOWED_IMAGE_MUTATIONS == {VERSION_PATH_IN_IMAGE}
  assert set(UPSTREAM_PROTECTED_PAYLOADS) >= {
    "/usr/comma/comma.sh",
    "/usr/comma/reset",
    "/usr/comma/setup",
    "/usr/comma/updater",
    "/etc/NetworkManager/NetworkManager.conf",
    "/etc/NetworkManager/conf.d/10-globally-managed-devices.conf",
    "/lib/systemd/system/NetworkManager.service",
  }


def test_starpilot_revision_maps_to_exact_upstream_version():
  assert expected_upstream_version("19.6.3", None) == "19.6"
  assert expected_upstream_version("19.6.3", "19.6-test") == "19.6-test"
  with pytest.raises(RuntimeError, match="revision suffix"):
    expected_upstream_version("19.6", None)


def test_official_source_hash_is_enforced(tmp_path):
  image = tmp_path / "official.img"
  image.write_bytes(b"official")
  digest = patch_image.sha256_file(image)

  assert verify_official_raw_hash({"hash_raw": digest}, image) == digest
  with pytest.raises(RuntimeError, match="hash mismatch"):
    verify_official_raw_hash({"hash_raw": "0" * 64}, image)


def test_write_rejects_non_version_path(tmp_path):
  with pytest.raises(RuntimeError, match="Refusing non-C3 AGNOS system mutation"):
    write_allowed_file("debugfs", tmp_path / "system.img", "/usr/comma/setup", tmp_path / "setup")


def test_upstream_manifest_cannot_be_primary(tmp_path):
  primary = tmp_path / "agnos.json"
  primary.write_text("[]")
  with pytest.raises(RuntimeError, match="Refusing to use StarPilot"):
    resolve_upstream_manifest(str(primary), primary)


def test_update_manifest_changes_only_system_entry():
  original = [
    {"name": "boot", "url": "custom-boot", "hash": "boot-hash"},
    {"name": "system", "url": "official", "hash": "old", "alt": {"url": "old-alt"}},
  ]
  updated = update_manifest_system_entry(original, "hosted", "new-hash", 123)

  assert updated[0] == original[0]
  assert updated[1] == {
    "name": "system",
    "url": "hosted",
    "hash": "new-hash",
    "hash_raw": "new-hash",
    "size": 123,
    "sparse": False,
    "full_check": False,
    "has_ab": True,
    "ondevice_hash": "new-hash",
  }
  assert json.dumps(original)
