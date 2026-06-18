#include "frogpilot/ui/qt/onroad/frogpilot_buttons.h"

DrivingPersonalityButton::DrivingPersonalityButton(QWidget *parent) : QPushButton(parent) {
  setFixedSize(btn_size + UI_BORDER_SIZE, btn_size);

  QObject::connect(frogpilotUIState(), &FrogPilotUIState::themeUpdated, this, &DrivingPersonalityButton::updateTheme);
  QObject::connect(this, &QPushButton::pressed, [this] {params_memory.putBool("OnroadDistanceButtonPressed", true);});
  QObject::connect(this, &QPushButton::released, [this] {params_memory.putBool("OnroadDistanceButtonPressed", false);});
}

void DrivingPersonalityButton::showEvent(QShowEvent *event) {
  updateTheme();
}

void DrivingPersonalityButton::updateTheme() {
  currentGif.clear();
  currentImg = QPixmap();

  theme_updated = true;
}

void DrivingPersonalityButton::updateState(const UIState &s, const FrogPilotUIState &fs) {
  const UIScene &scene = s.scene;

  const SubMaster &fpsm = *(fs.sm);

  const cereal::FrogPilotCarState::Reader &frogpilotCarState = fpsm["frogpilotCarState"].getFrogpilotCarState();

  bool new_traffic_mode_active = frogpilotCarState.getTrafficModeEnabled();

  int new_personality = static_cast<int>(scene.personality) + 1;

  bool state_changed = (traffic_mode_active != new_traffic_mode_active) ||
                       (personality != new_personality && !new_traffic_mode_active);

  if (!state_changed && !theme_updated) {
    return;
  }

  traffic_mode_active = new_traffic_mode_active;

  personality = new_personality;

  theme_updated = false;

  QString icon;
  if (traffic_mode_active) {
    icon = "traffic";
  } else if (personality == 1) {
    icon = "aggressive";
  } else if (personality == 2) {
    icon = "standard";
  } else if (personality == 3) {
    icon = "relaxed";
  }

  loadImage("../../frogpilot/assets/active_theme/distance_icons/" + icon, currentImg, currentGif, QSize(btn_size, btn_size), this);
}

void DrivingPersonalityButton::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  p.setRenderHint(QPainter::Antialiasing);

  drawIcon(p, rect().center() + QPoint(UI_BORDER_SIZE / 2, 0), currentGif ? currentGif->currentPixmap() : currentImg, Qt::transparent, 1.0);
}
