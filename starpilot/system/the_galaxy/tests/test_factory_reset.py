import importlib.util
import subprocess

import pytest

from pathlib import Path


def _load_factory_reset_module():
  spec = importlib.util.spec_from_file_location("factory_reset_under_test", Path(__file__).resolve().parents[1] / "factory_reset.py")
  module = importlib.util.module_from_spec(spec)
  spec.loader.exec_module(module)
  return module


factory_reset = _load_factory_reset_module()


def test_request_system_factory_reset_uses_agnos_uninstall(monkeypatch):
  calls = []
  monkeypatch.setattr(factory_reset.HARDWARE, "uninstall", lambda: calls.append(True))

  factory_reset.request_system_factory_reset()

  assert calls == [True]


def test_galaxy_factory_reset_worker_does_not_partially_delete_userdata():
  source = (Path(__file__).resolve().parents[1] / "the_galaxy.py").read_text(encoding="utf-8")
  worker = source.split("def _factory_reset_worker():", 1)[1].split("\ndef ", 1)[0]

  assert "_request_system_factory_reset()" in worker
  assert "_run_factory_reset_delete" not in worker
  assert "_finish_update_and_reboot" not in worker


def test_remove_path_retries_directory_not_empty(monkeypatch):
  results = iter(
    [
      subprocess.CompletedProcess([], 1, stderr="rm: cannot remove '/data/params': Directory not empty"),
      subprocess.CompletedProcess([], 0),
    ]
  )
  calls = []
  sleeps = []

  def fake_run(*args, **kwargs):
    calls.append((args, kwargs))
    return next(results)

  monkeypatch.setattr(factory_reset.subprocess, "run", fake_run)
  monkeypatch.setattr(factory_reset.time, "sleep", sleeps.append)

  factory_reset.remove_path("/data/params")

  assert len(calls) == 2
  assert calls[0][0][0] == ["sudo", "rm", "-rf", "--", "/data/params"]
  assert sleeps == [factory_reset._DELETE_RETRY_DELAY_S]


def test_remove_path_does_not_retry_non_transient_error(monkeypatch):
  calls = []

  def fake_run(*args, **kwargs):
    calls.append((args, kwargs))
    return subprocess.CompletedProcess([], 1, stderr="rm: cannot remove '/data/params': Permission denied")

  monkeypatch.setattr(factory_reset.subprocess, "run", fake_run)

  with pytest.raises(RuntimeError, match="Permission denied"):
    factory_reset.remove_path("/data/params")

  assert len(calls) == 1
