#!/usr/bin/env python3
"""Build StarPilot's AGNOS system image from an official upstream image.

The system payload must remain upstream-identical except for /VERSION. C3
compatibility stays outside this system image in the manifest's known-good C3
bootloader/boot partitions and in StarPilot's runtime. Reset, setup, networking,
and updater behavior remain owned by upstream AGNOS.
"""

import argparse
import hashlib
import json
import os
import shutil
import struct
import subprocess
import urllib.request
from pathlib import Path


VERSION_PATH_IN_IMAGE = "/VERSION"
ALLOWED_IMAGE_MUTATIONS = frozenset({VERSION_PATH_IN_IMAGE})

UPSTREAM_PROTECTED_PAYLOADS = (
  "/usr/comma/comma.sh",
  "/usr/comma/reset",
  "/usr/comma/setup",
  "/usr/comma/updater",
  "/etc/NetworkManager/NetworkManager.conf",
  "/etc/NetworkManager/conf.d/10-globally-managed-devices.conf",
  "/lib/systemd/system/NetworkManager.service",
)

ANDROID_SPARSE_MAGIC = 0xED26FF3A
CHUNK_TYPE_RAW = 0xCAC1
CHUNK_TYPE_FILL = 0xCAC2
CHUNK_TYPE_DONT_CARE = 0xCAC3
CHUNK_TYPE_CRC32 = 0xCAC4
XZ_MAGIC = b"\xFD7zXZ\x00"


def parse_args() -> argparse.Namespace:
  parser = argparse.ArgumentParser(
    description="Create a stock AGNOS system image with only StarPilot's version marker changed",
  )
  parser.add_argument("--manifest", default="system/hardware/tici/agnos.json",
                      help="StarPilot manifest to update after the image is hosted")
  parser.add_argument("--upstream-manifest", default=None,
                      help="Official openpilot AGNOS manifest used as the system-image source")
  parser.add_argument("--source-url", default=None,
                      help="Override the official system image URL")
  parser.add_argument("--source-image", default=None,
                      help="Use an already-downloaded official system image")
  parser.add_argument("--expected-source-version", default=None,
                      help="Fail unless the official image has this /VERSION")
  parser.add_argument("--set-version", required=True,
                      help="StarPilot AGNOS version written to /VERSION")
  parser.add_argument("--work-dir", default=".cache/agnos_stock_c3",
                      help="Directory for downloaded and generated images")
  parser.add_argument("--output-xz", default=None, help="Output .img.xz path")
  parser.add_argument("--new-url", default=None,
                      help="Hosted output URL; enables manifest generation")
  parser.add_argument("--manifest-out", default=None,
                      help="Write the updated StarPilot manifest here")
  parser.add_argument("--in-place-manifest", action="store_true",
                      help="Update --manifest in place")
  parser.add_argument("--force-download", action="store_true")
  return parser.parse_args()


def find_debugfs() -> str:
  candidates = (
    os.environ.get("DEBUGFS"),
    "debugfs",
    "/opt/homebrew/opt/e2fsprogs/sbin/debugfs",
  )
  for candidate in candidates:
    if candidate and (shutil.which(candidate) or Path(candidate).is_file()):
      return candidate
  raise RuntimeError("debugfs not found. Install e2fsprogs and retry.")


def load_manifest(path: Path) -> list[dict]:
  return json.loads(path.read_text(encoding="utf-8"))


def get_system_entry(manifest: list[dict]) -> dict:
  for entry in manifest:
    if entry.get("name") == "system":
      return entry
  raise RuntimeError("No system entry found in manifest")


def find_default_upstream_manifest(primary_manifest_path: Path) -> Path | None:
  repo_root = Path(__file__).resolve().parents[2]
  candidates = (
    repo_root.parent / "openpilot/openpilot/common/hardware/comma/agnos.json",
    repo_root.parent / "openpilot/openpilot/system/hardware/comma/agnos.json",
    repo_root.parent / "openpilot/openpilot/system/hardware/tici/agnos.json",
    repo_root.parent / "openpilot/system/hardware/tici/agnos.json",
  )
  primary = primary_manifest_path.resolve()
  for candidate in candidates:
    if candidate.is_file() and candidate.resolve() != primary:
      return candidate.resolve()
  return None


def resolve_upstream_manifest(explicit_path: str | None, primary_manifest_path: Path) -> Path:
  upstream = Path(explicit_path).resolve() if explicit_path else find_default_upstream_manifest(primary_manifest_path)
  if upstream is None or not upstream.is_file():
    raise RuntimeError("Official upstream AGNOS manifest not found; pass --upstream-manifest")
  if upstream.resolve() == primary_manifest_path.resolve():
    raise RuntimeError("Refusing to use StarPilot's manifest as the stock source")
  return upstream


def pick_source_url(system_entry: dict, override: str | None) -> str:
  if override:
    return override
  url = system_entry.get("url")
  if not isinstance(url, str) or not url:
    raise RuntimeError("Official system manifest entry has no URL")
  return url


def expected_upstream_version(starpilot_version: str, explicit_version: str | None) -> str:
  if explicit_version:
    return explicit_version.strip()
  parts = starpilot_version.strip().split(".")
  if len(parts) < 3:
    raise RuntimeError("Pass --expected-source-version when --set-version has no StarPilot revision suffix")
  return ".".join(parts[:-1])


def download(url: str, destination: Path) -> None:
  destination.parent.mkdir(parents=True, exist_ok=True)
  partial = destination.with_suffix(destination.suffix + ".part")
  print(f"Downloading official AGNOS system image: {url}", flush=True)
  with urllib.request.urlopen(url) as response, open(partial, "wb") as output:
    shutil.copyfileobj(response, output, length=8 * 1024 * 1024)
  partial.replace(destination)


def run_cmd(cmd: list[str], capture: bool = True) -> subprocess.CompletedProcess[str]:
  result = subprocess.run(cmd, check=False, capture_output=capture, text=True)
  if result.returncode != 0:
    output = f"{result.stdout}\n{result.stderr}" if capture else ""
    raise RuntimeError(f"Command failed ({result.returncode}): {' '.join(cmd)}\n{output}")
  return result


def is_xz_file(path: Path) -> bool:
  with open(path, "rb") as stream:
    return stream.read(len(XZ_MAGIC)) == XZ_MAGIC


def decompress_xz(source: Path, destination: Path) -> None:
  partial = destination.with_suffix(destination.suffix + ".part")
  print(f"Decompressing {source}", flush=True)
  with open(partial, "wb") as output:
    result = subprocess.run(["xz", "-T0", "-dc", str(source)], stdout=output, stderr=subprocess.PIPE)
  if result.returncode != 0:
    partial.unlink(missing_ok=True)
    raise RuntimeError(f"xz failed: {result.stderr.decode('utf-8', 'replace')}")
  partial.replace(destination)


def is_android_sparse(path: Path) -> bool:
  with open(path, "rb") as stream:
    raw = stream.read(4)
  return len(raw) == 4 and struct.unpack("<I", raw)[0] == ANDROID_SPARSE_MAGIC


def unsparse_image(source: Path, destination: Path) -> None:
  print(f"Converting Android sparse image {source}", flush=True)
  with open(source, "rb") as source_file, open(destination, "wb") as output:
    header = source_file.read(28)
    if len(header) != 28:
      raise RuntimeError("Sparse image header is truncated")
    magic, major, _minor, file_header_size, chunk_header_size, block_size, total_blocks, total_chunks, _checksum = struct.unpack(
      "<I4H4I", header,
    )
    if magic != ANDROID_SPARSE_MAGIC or major != 1:
      raise RuntimeError("Unsupported Android sparse image")
    if file_header_size > 28:
      source_file.read(file_header_size - 28)

    for _ in range(total_chunks):
      chunk_header = source_file.read(chunk_header_size)
      if len(chunk_header) != chunk_header_size:
        raise RuntimeError("Sparse chunk header is truncated")
      chunk_type, _reserved, chunk_blocks, total_size = struct.unpack("<2H2I", chunk_header[:12])
      payload_size = total_size - chunk_header_size
      output_size = chunk_blocks * block_size

      if chunk_type == CHUNK_TYPE_RAW:
        if payload_size != output_size:
          raise RuntimeError("Sparse RAW chunk size mismatch")
        remaining = payload_size
        while remaining:
          chunk = source_file.read(min(8 * 1024 * 1024, remaining))
          if not chunk:
            raise RuntimeError("Sparse RAW chunk is truncated")
          output.write(chunk)
          remaining -= len(chunk)
      elif chunk_type == CHUNK_TYPE_FILL:
        if payload_size != 4:
          raise RuntimeError("Sparse FILL chunk has invalid size")
        pattern = source_file.read(4)
        if pattern == b"\0\0\0\0":
          output.seek(output_size, os.SEEK_CUR)
        else:
          unit = pattern * (block_size // 4)
          for _ in range(chunk_blocks):
            output.write(unit)
      elif chunk_type == CHUNK_TYPE_DONT_CARE:
        if payload_size:
          source_file.read(payload_size)
        output.seek(output_size, os.SEEK_CUR)
      elif chunk_type == CHUNK_TYPE_CRC32:
        if payload_size != 4:
          raise RuntimeError("Sparse CRC32 chunk has invalid size")
        source_file.read(4)
      else:
        raise RuntimeError(f"Unknown sparse chunk type: 0x{chunk_type:04x}")

    output.truncate(total_blocks * block_size)


def materialize_ext4_image(source: Path, destination: Path, work_dir: Path, force: bool = False) -> None:
  candidate = source
  if is_xz_file(source):
    decompressed = work_dir / "official_system.decompressed.img"
    if force:
      decompressed.unlink(missing_ok=True)
    if not decompressed.exists():
      decompress_xz(source, decompressed)
    candidate = decompressed

  if force:
    destination.unlink(missing_ok=True)
  if destination.exists():
    return
  if is_android_sparse(candidate):
    unsparse_image(candidate, destination)
  else:
    shutil.copy2(candidate, destination)


def run_debugfs(debugfs: str, image: Path, request: str, write: bool = False) -> str:
  command = [debugfs]
  if write:
    command.append("-w")
  command += ["-R", request, str(image)]
  result = run_cmd(command)
  return f"{result.stdout}\n{result.stderr}"


def parse_inode(debugfs_output: str) -> int:
  for line in debugfs_output.splitlines():
    if "Inode:" in line:
      value = line.split("Inode:", 1)[1].strip().split()[0]
      return int(value)
  raise RuntimeError(f"Unable to parse inode from debugfs output:\n{debugfs_output}")


def write_allowed_file(debugfs: str, image: Path, image_path: str, local_file: Path,
                       mode_octal: str = "100644", uid: int = 0, gid: int = 0) -> None:
  if image_path not in ALLOWED_IMAGE_MUTATIONS:
    raise RuntimeError(f"Refusing non-C3 AGNOS system mutation: {image_path}")

  try:
    run_debugfs(debugfs, image, f"rm {image_path}", write=True)
  except RuntimeError as error:
    if "file not found" not in str(error).lower() and "no such file" not in str(error).lower():
      raise
  run_debugfs(debugfs, image, f"write {local_file} {image_path}", write=True)
  inode = parse_inode(run_debugfs(debugfs, image, f"stat {image_path}"))
  for field, value in (("mode", f"0{int(mode_octal, 8):o}"), ("uid", str(uid)), ("gid", str(gid))):
    run_debugfs(debugfs, image, f"set_inode_field <{inode}> {field} {value}", write=True)


def sha256_file(path: Path) -> str:
  digest = hashlib.sha256()
  with open(path, "rb") as stream:
    while chunk := stream.read(1024 * 1024):
      digest.update(chunk)
  return digest.hexdigest()


def verify_official_raw_hash(system_entry: dict, official_raw: Path) -> str:
  expected = system_entry.get("hash_raw")
  if not isinstance(expected, str) or not expected:
    raise RuntimeError("Official system manifest entry has no hash_raw")
  actual = sha256_file(official_raw)
  if actual != expected.lower():
    raise RuntimeError(f"Official system image hash mismatch: got {actual}, expected {expected.lower()}")
  return actual


def fingerprint_image_paths(debugfs: str, image: Path, paths: tuple[str, ...], work_dir: Path,
                            label: str) -> dict[str, str]:
  output_dir = work_dir / f"fingerprints_{label}"
  output_dir.mkdir(parents=True, exist_ok=True)
  fingerprints: dict[str, str] = {}
  for image_path in paths:
    local_path = output_dir / image_path.strip("/").replace("/", "_")
    local_path.unlink(missing_ok=True)
    run_debugfs(debugfs, image, f"dump -p {image_path} {local_path}")
    fingerprints[image_path] = sha256_file(local_path)
  return fingerprints


def read_image_text(debugfs: str, image: Path, image_path: str) -> str:
  output = run_debugfs(debugfs, image, f"cat {image_path}")
  lines = [line.strip() for line in output.splitlines() if line.strip() and not line.startswith("debugfs ")]
  return lines[0] if lines else ""


def compress_xz(source: Path, destination: Path) -> None:
  destination.parent.mkdir(parents=True, exist_ok=True)
  partial = destination.with_suffix(destination.suffix + ".part")
  print(f"Compressing {source} -> {destination}", flush=True)
  with open(partial, "wb") as output:
    result = subprocess.run(["xz", "-T0", "-6", "-c", str(source)], stdout=output, stderr=subprocess.PIPE)
  if result.returncode != 0:
    partial.unlink(missing_ok=True)
    raise RuntimeError(f"xz failed: {result.stderr.decode('utf-8', 'replace')}")
  partial.replace(destination)


def write_artifact_metadata(destination: Path, *, upstream_manifest: Path, upstream_version: str,
                            starpilot_version: str, raw_hash: str, raw_size: int,
                            protected_hashes: dict[str, str]) -> Path:
  metadata_path = Path(str(destination) + ".metadata.json")
  metadata = {
    "upstream_manifest": str(upstream_manifest),
    "upstream_version": upstream_version,
    "starpilot_version": starpilot_version,
    "raw_sha256": raw_hash,
    "raw_size": raw_size,
    "xz_sha256": sha256_file(destination),
    "xz_size": destination.stat().st_size,
    "protected_upstream_payloads": protected_hashes,
  }
  metadata_path.write_text(json.dumps(metadata, indent=2) + "\n", encoding="utf-8")
  return metadata_path


def update_manifest_system_entry(manifest: list[dict], new_url: str, raw_hash: str, size: int) -> list[dict]:
  updated = json.loads(json.dumps(manifest))
  entry = get_system_entry(updated)
  entry.update({
    "url": new_url,
    "hash": raw_hash,
    "hash_raw": raw_hash,
    "size": size,
    "sparse": False,
    "full_check": False,
    "has_ab": True,
    "ondevice_hash": raw_hash,
  })
  entry.pop("alt", None)
  entry.pop("casync_caibx", None)
  entry.pop("casync_store", None)
  return updated


def main() -> int:
  args = parse_args()
  debugfs = find_debugfs()
  target_manifest_path = Path(args.manifest).resolve()
  target_manifest = load_manifest(target_manifest_path)
  upstream_manifest_path = resolve_upstream_manifest(args.upstream_manifest, target_manifest_path)
  upstream_manifest = load_manifest(upstream_manifest_path)
  upstream_system_entry = get_system_entry(upstream_manifest)

  work_dir = Path(args.work_dir).resolve()
  work_dir.mkdir(parents=True, exist_ok=True)
  if args.source_image:
    source = Path(args.source_image).resolve()
    if not source.is_file():
      raise RuntimeError(f"Official source image not found: {source}")
  else:
    source = work_dir / "official_system.payload"
    if args.force_download:
      source.unlink(missing_ok=True)
    if not source.exists():
      download(pick_source_url(upstream_system_entry, args.source_url), source)

  official_raw = work_dir / "official_system.ext4.img"
  materialize_ext4_image(source, official_raw, work_dir, force=args.force_download)
  verify_official_raw_hash(upstream_system_entry, official_raw)
  source_version = read_image_text(debugfs, official_raw, VERSION_PATH_IN_IMAGE)
  required_source_version = expected_upstream_version(args.set_version, args.expected_source_version)
  if source_version != required_source_version:
    raise RuntimeError(
      f"Official source /VERSION is {source_version!r}, expected {required_source_version!r}",
    )

  patched_raw = work_dir / "starpilot_system.ext4.img"
  patched_raw.unlink(missing_ok=True)
  shutil.copy2(official_raw, patched_raw)

  before = fingerprint_image_paths(debugfs, official_raw, UPSTREAM_PROTECTED_PAYLOADS, work_dir, "official")
  version_file = work_dir / "VERSION.starpilot"
  version_file.write_text(args.set_version.strip() + "\n", encoding="utf-8")
  write_allowed_file(debugfs, patched_raw, VERSION_PATH_IN_IMAGE, version_file)
  after = fingerprint_image_paths(debugfs, patched_raw, UPSTREAM_PROTECTED_PAYLOADS, work_dir, "starpilot")
  if before != after:
    changed = sorted(path for path in before if before[path] != after.get(path))
    raise RuntimeError(f"Upstream recovery payload changed unexpectedly: {changed}")
  if read_image_text(debugfs, patched_raw, VERSION_PATH_IN_IMAGE) != args.set_version.strip():
    raise RuntimeError("Failed to write StarPilot AGNOS version marker")

  raw_hash = sha256_file(patched_raw)
  raw_size = patched_raw.stat().st_size
  output_xz = Path(args.output_xz).resolve() if args.output_xz else work_dir / f"system-{raw_hash}.img.xz"
  compress_xz(patched_raw, output_xz)
  metadata_path = write_artifact_metadata(
    output_xz,
    upstream_manifest=upstream_manifest_path,
    upstream_version=source_version,
    starpilot_version=args.set_version.strip(),
    raw_hash=raw_hash,
    raw_size=raw_size,
    protected_hashes=after,
  )

  print("Stock-plus-C3 AGNOS system artifact ready:")
  print(f"  upstream manifest: {upstream_manifest_path}")
  print(f"  upstream version:  {source_version}")
  print(f"  StarPilot version: {args.set_version.strip()}")
  print(f"  raw image:         {patched_raw}")
  print(f"  xz image:          {output_xz}")
  print(f"  raw sha256:        {raw_hash}")
  print(f"  raw size:          {raw_size}")
  print(f"  metadata:          {metadata_path}")
  print("  protected payloads: byte-identical to upstream")

  if args.new_url:
    updated_manifest = update_manifest_system_entry(target_manifest, args.new_url, raw_hash, raw_size)
    if args.in_place_manifest:
      output_manifest = target_manifest_path
    elif args.manifest_out:
      output_manifest = Path(args.manifest_out).resolve()
    else:
      output_manifest = work_dir / "agnos.starpilot.json"
    output_manifest.write_text(json.dumps(updated_manifest, indent=2) + "\n", encoding="utf-8")
    print(f"  updated manifest:  {output_manifest}")
  else:
    print("No --new-url supplied; the checked-in manifest was not changed.")
  return 0


if __name__ == "__main__":
  raise SystemExit(main())
