from __future__ import annotations

import json
from typing import Any

import numpy as np

MODEL_LAB_CONFIG_PARAM = "ModelLabConfig"
MODEL_LAB_RUNTIME_PARAM = "ModelLabRuntime"
MODEL_LAB_MIN_MODEL_VERSION = 8

LATERAL_OUTPUT_KEYS = (
  "desired_curvature",
  "desired_curvature_stds",
  "lat_planner_solution",
  "lat_planner_solution_stds",
  "lane_lines",
  "lane_lines_stds",
  "lane_lines_prob",
  "road_edges",
  "road_edges_stds",
  "desire_state",
  "desire_pred",
)

CURRENT_FRAME_OUTPUT_KEYS = (
  "pose",
  "pose_stds",
  "wide_from_device_euler",
  "wide_from_device_euler_stds",
  "road_transform",
  "road_transform_stds",
)

LATERAL_PLAN_COLUMNS = (1, 4, 7, 11, 14)


def parse_model_version(version: Any) -> int | None:
  text = str(version or "").strip().lower()
  if not text.startswith("v") or not text[1:].isdigit():
    return None
  return int(text[1:])


def model_lab_version_supported(version: Any) -> bool:
  parsed = parse_model_version(version)
  return parsed is not None and parsed >= MODEL_LAB_MIN_MODEL_VERSION


def is_small_model_metadata(metadata: dict[str, Any] | None) -> bool:
  metadata = metadata if isinstance(metadata, dict) else {}
  if bool(metadata.get("uses_external_gpu", False)):
    return False
  size_class = str(metadata.get("model_size") or metadata.get("size_class") or "").strip().lower()
  if size_class:
    return size_class in {"small", "standard", "on_device", "on-device"}

  return True


def model_lab_manifest_eligible(metadata: dict[str, Any] | None, version: Any) -> bool:
  metadata = metadata if isinstance(metadata, dict) else {}
  explicit = metadata.get("model_lab_eligible")
  if explicit is not None and not bool(explicit):
    return False
  return is_small_model_metadata(metadata) and model_lab_version_supported(version)


def normalize_model_lab_config(value: Any) -> dict[str, Any]:
  if isinstance(value, bytes):
    value = value.decode("utf-8", errors="ignore")
  if isinstance(value, str):
    try:
      value = json.loads(value) if value.strip() else {}
    except (TypeError, ValueError):
      value = {}
  if not isinstance(value, dict):
    value = {}

  return {
    "enabled": bool(value.get("enabled", False)),
    "lateralModel": str(value.get("lateralModel") or "").strip(),
    "longitudinalModel": str(value.get("longitudinalModel") or "").strip(),
  }


def load_model_lab_config(params) -> dict[str, Any]:
  try:
    return normalize_model_lab_config(params.get(MODEL_LAB_CONFIG_PARAM))
  except Exception:
    return normalize_model_lab_config(None)


def validate_model_lab_selection(
  config: Any,
  catalog: dict[str, dict[str, Any]],
  *,
  chestnut_ready: bool,
  require_installed: bool = True,
) -> str | None:
  normalized = normalize_model_lab_config(config)
  if not normalized["enabled"]:
    return None
  if not chestnut_ready:
    return "Chestnut is not connected and firmware-ready."

  lateral_id = normalized["lateralModel"]
  longitudinal_id = normalized["longitudinalModel"]
  if not lateral_id or not longitudinal_id:
    return "Choose both a lateral and a longitudinal model."
  if lateral_id == longitudinal_id:
    return "Choose two different small models."

  for role, model_id in (("Lateral", lateral_id), ("Longitudinal", longitudinal_id)):
    model = catalog.get(model_id)
    if model is None:
      return f"{role} model '{model_id}' is not in the current manifest."
    if not bool(model.get("small", False)):
      return f"{role} model '{model_id}' is Chestnut-class, not a small model."
    if not bool(model.get("modelLabEligible", False)):
      return f"{role} model '{model_id}' is not compatible with Model Laboratory."
    if not bool(model.get("modelLabArtifactAvailable", False)):
      return f"{role} model '{model_id}' has no precompiled AMD artifact in the current manifest."
    if require_installed and not bool(model.get("modelLabArtifactInstalled", False)):
      return f"{role} model '{model_id}' has not downloaded its precompiled AMD artifact."

  lateral_version = str(catalog[lateral_id].get("version") or "").strip()
  longitudinal_version = str(catalog[longitudinal_id].get("version") or "").strip()
  if lateral_version != longitudinal_version:
    return "Choose models from the same behavior version; the longitudinal planner currently has one shared version contract."
  return None


def _merge_plan_tensor(lateral: np.ndarray, longitudinal: np.ndarray) -> np.ndarray:
  if lateral.shape != longitudinal.shape or lateral.ndim < 2 or lateral.shape[-1] < 15:
    raise ValueError(
      f"Model Laboratory plan tensors are incompatible: lateral={lateral.shape}, longitudinal={longitudinal.shape}"
    )
  merged = longitudinal.copy()
  merged[..., LATERAL_PLAN_COLUMNS] = lateral[..., LATERAL_PLAN_COLUMNS]
  return merged


def _merge_action_tensor(lateral: np.ndarray, longitudinal: np.ndarray) -> np.ndarray:
  if lateral.shape != longitudinal.shape or lateral.ndim < 1 or lateral.shape[-1] < 2:
    raise ValueError(
      f"Model Laboratory action tensors are incompatible: lateral={lateral.shape}, longitudinal={longitudinal.shape}"
    )
  merged = longitudinal.copy()
  merged[..., 0] = lateral[..., 0]
  return merged


def compose_model_outputs(
  lateral_output: dict[str, np.ndarray],
  longitudinal_output: dict[str, np.ndarray],
  current_frame_output: dict[str, np.ndarray] | None = None,
) -> dict[str, np.ndarray]:
  """Compose normalized model outputs without mutating either runner's state."""
  if "plan" not in lateral_output or "plan" not in longitudinal_output:
    raise ValueError("Model Laboratory requires a plan output from both models.")

  composed = dict(longitudinal_output)
  composed["plan"] = _merge_plan_tensor(lateral_output["plan"], longitudinal_output["plan"])

  if ("plan_stds" in lateral_output) != ("plan_stds" in longitudinal_output):
    raise ValueError("Model Laboratory requires matching plan uncertainty outputs.")
  if "plan_stds" in lateral_output and "plan_stds" in longitudinal_output:
    composed["plan_stds"] = _merge_plan_tensor(lateral_output["plan_stds"], longitudinal_output["plan_stds"])
  else:
    composed.pop("plan_stds", None)

  if ("action" in lateral_output) != ("action" in longitudinal_output):
    raise ValueError("Model Laboratory requires matching action outputs.")
  if "action" in lateral_output and "action" in longitudinal_output:
    composed["action"] = _merge_action_tensor(lateral_output["action"], longitudinal_output["action"])
  else:
    composed.pop("action", None)
  if ("action_stds" in lateral_output) != ("action_stds" in longitudinal_output):
    raise ValueError("Model Laboratory requires matching action uncertainty outputs.")
  if "action_stds" in lateral_output and "action_stds" in longitudinal_output:
    composed["action_stds"] = _merge_action_tensor(lateral_output["action_stds"], longitudinal_output["action_stds"])
  else:
    composed.pop("action_stds", None)

  for key in LATERAL_OUTPUT_KEYS:
    if key in lateral_output:
      composed[key] = lateral_output[key]
    else:
      composed.pop(key, None)
  current_frame_output = lateral_output if current_frame_output is None else current_frame_output
  for key in CURRENT_FRAME_OUTPUT_KEYS:
    if key in current_frame_output:
      composed[key] = current_frame_output[key]
    else:
      composed.pop(key, None)
  return composed


def hybrid_action_values(lateral_action: Any, longitudinal_action: Any) -> dict[str, Any]:
  return {
    "desiredCurvature": float(lateral_action.desiredCurvature),
    "desiredAcceleration": float(longitudinal_action.desiredAcceleration),
    "shouldStop": bool(longitudinal_action.shouldStop),
  }
