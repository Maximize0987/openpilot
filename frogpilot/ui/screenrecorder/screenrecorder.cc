#include "frogpilot/ui/screenrecorder/screenrecorder.h"

#include <cmath>

#include <QOpenGLWidget>

#include "common/timing.h"
#include "selfdrive/ui/qt/util.h"

namespace {
constexpr int RECORD_BITRATE = 10 * 1024 * 1024;
constexpr int SCREEN_HEIGHT = 1080;
constexpr int SCREEN_WIDTH = 2160;
}

ScreenRecorder::ScreenRecorder(QWidget *parent) : QPushButton(parent) {
  setFixedSize(btn_size, btn_size);

  rootWidget = topWidget(this);
  engine = std::make_unique<RecorderEngine>(SCREEN_WIDTH, SCREEN_HEIGHT, UI_FREQ, RECORD_BITRATE);

  QObject::connect(this, &QPushButton::clicked, this, &ScreenRecorder::toggleRecording);
  QObject::connect(uiState(), &UIState::offroadTransition, this, &ScreenRecorder::stopRecording);
  QObject::connect(uiState(), &UIState::uiUpdate, this, &ScreenRecorder::updateState);
}

ScreenRecorder::~ScreenRecorder() {
  if (engine) {
    engine->stop();
  }
}

void ScreenRecorder::updateState() {
  if (stopping) {
    if (engine->stop_complete()) {
      stopping = false;
      emit recordingStateChanged(false);
    }
    return;
  }

  if (!recording) {
    return;
  }

  if (!engine->is_recording()) {
    if (auto *camera = qobject_cast<QOpenGLWidget *>(parentWidget())) {
      camera->setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
    }
    engine->request_stop();

    recording = false;
    stopping = !engine->stop_complete();

    update();

    if (!stopping) {
      emit recordingStateChanged(false);
    }

    return;
  }

  if (frameCount++ % 2 == 0 && engine->can_accept_frame()) {
    engine->submit_frame(rootWidget->grab().toImage(), nanos_since_boot());
  }
}

void ScreenRecorder::toggleRecording() {
  if (stopping) {
    return;
  }

  if (recording) {
    stopRecording();
  } else {
    startRecording();
  }
}

bool ScreenRecorder::startRecording() {
  if (recording) {
    return true;
  }
  if (stopping) {
    return false;
  }

  if (!engine->start()) {
    return false;
  }

  if (auto *camera = qobject_cast<QOpenGLWidget *>(parentWidget())) {
    camera->setUpdateBehavior(QOpenGLWidget::PartialUpdate);
  }

  recording = true;

  frameCount = 1;

  startedTime = QDateTime::currentMSecsSinceEpoch();

  update();

  emit recordingStateChanged(true);

  return true;
}

void ScreenRecorder::stopRecording() {
  if (!recording) {
    return;
  }

  recording = false;
  stopping = true;

  if (auto *camera = qobject_cast<QOpenGLWidget *>(parentWidget())) {
    camera->setUpdateBehavior(QOpenGLWidget::NoPartialUpdate);
  }
  engine->request_stop();

  update();
}

void ScreenRecorder::paintEvent(QPaintEvent *event) {
  QPainter p(this);
  p.setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

  if (recording) {
    qint64 elapsed = QDateTime::currentMSecsSinceEpoch() - startedTime;

    qreal phase = (elapsed % 2000) / 2000.0 * 2 * M_PI;
    qreal alphaFactor = 0.5 + 0.5 * sin(phase);

    QColor glowColor = redColor();
    glowColor.setAlphaF(0.3 + 0.7 * alphaFactor);

    int glowWidth = 8 + static_cast<int>(2 * alphaFactor);

    p.setBrush(blackColor(166));
    p.setFont(InterFont(25, QFont::Bold));
    p.setPen(QPen(glowColor, glowWidth));
  } else {
    p.setBrush(blackColor(166));
    p.setFont(InterFont(25, QFont::DemiBold));
    p.setPen(QPen(redColor(), 8));
  }

  int centeringOffset = 10;

  QRect buttonRect(centeringOffset, btn_size / 3, btn_size - centeringOffset * 2, btn_size / 3);
  p.drawRoundedRect(buttonRect, 24, 24);

  QRect textRect = buttonRect.adjusted(centeringOffset, 0, -centeringOffset, 0);
  p.setPen(QPen(whiteColor(), 6));
  p.drawText(textRect, Qt::AlignLeft | Qt::AlignVCenter, recording ? tr("RECORDING") : tr("RECORD"));

  if (!recording) {
    p.setBrush(redColor(166));
    p.setPen(Qt::NoPen);
    p.drawEllipse(QPoint(buttonRect.right() - btn_size / 10 - centeringOffset, buttonRect.center().y()), btn_size / 10, btn_size / 10);
  }
}
