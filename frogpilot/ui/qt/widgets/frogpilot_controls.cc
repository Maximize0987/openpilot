#include "selfdrive/ui/ui.h"

#include "frogpilot/ui/frogpilot_ui.h"

bool FrogPilotConfirmationDialog::toggleReboot(QWidget *parent) {
  ConfirmationDialog d(tr("Reboot required to take effect."), tr("Reboot Now"), tr("Reboot Later"), false, parent);
  return d.exec();
}

bool FrogPilotConfirmationDialog::yesorno(const QString &prompt_text, QWidget *parent) {
  ConfirmationDialog d(prompt_text, tr("Yes"), tr("No"), false, parent);
  return d.exec();
}

bool isFrogsGoMoo() {
  static bool is_FrogsGoMoo = QFile::exists("/persist/frogsgomoo.py");
  return is_FrogsGoMoo;
}

bool useKonikServer() {
  static bool use_konik = QFile::exists("/cache/use_konik");
  return use_konik;
}

void clearMovie(QSharedPointer<QMovie> &movie, QWidget *parent) {
  if (!movie) {
    return;
  }

  QObject::disconnect(movie.data(), nullptr, parent, nullptr);
  movie->stop();
  movie.reset();
}

void loadGif(const QString &gifPath, QSharedPointer<QMovie> &movie, const QSize &size, QWidget *parent, bool repaintOnFrame) {
  if (!parent) {
    return;
  }

  if (gifPath.isEmpty()) {
    clearMovie(movie, parent);
    return;
  }

  QFileInfo gifInfo(gifPath);
  if (!gifInfo.exists()) {
    clearMovie(movie, parent);
    return;
  }

  QString sourcePath = gifInfo.canonicalFilePath();
  if (sourcePath.isEmpty()) {
    sourcePath = gifInfo.absoluteFilePath();
  }

  if (movie && movie->property("sourcePath").toString() == sourcePath && movie->state() == QMovie::Running) {
    if (movie->scaledSize() != size) {
      movie->setScaledSize(size);
    }
    return;
  }

  clearMovie(movie, parent);

  movie = QSharedPointer<QMovie>::create(gifPath);
  movie->setProperty("sourcePath", sourcePath);
  movie->setCacheMode(QMovie::CacheAll);
  movie->setScaledSize(size);

  if (repaintOnFrame) {
    QPointer<QWidget> safeParent(parent);
    QObject::connect(movie.data(), &QMovie::frameChanged, parent, [safeParent]() {
      if (safeParent && safeParent->isVisible()) {
        safeParent->update();
      }
    });
  }

  movie->start();
}

void loadImage(const QString &basePath, QPixmap &pixmap, QSharedPointer<QMovie> &movie, const QSize &size, QWidget *parent) {
  if (!parent) {
    return;
  }

  const QString gifPath = basePath + ".gif";
  if (QFileInfo::exists(gifPath)) {
    pixmap = QPixmap();
    loadGif(gifPath, movie, size, parent);
  } else {
    clearMovie(movie, parent);

    QPixmap loadedPixmap(basePath + ".png");
    pixmap = loadedPixmap.isNull() ? QPixmap() : loadedPixmap.scaled(size, Qt::KeepAspectRatio, Qt::SmoothTransformation);
  }

  parent->update();
}

void openDescriptions(bool forceOpenDescriptions, std::map<QString, AbstractControl*> toggles) {
  if (forceOpenDescriptions) {
    for (auto &[key, toggle] : toggles) {
      if (key != "CESpeed") {
        toggle->showDescription();
      }
    }
  }
}

void updateFrogPilotToggles() {
  static Params params_memory{"", true};
  params_memory.putBool("FrogPilotTogglesUpdated", true);
}

QString cleanModelName(QString modelName) {
  return modelName.remove("_default").remove("(Default)");
}
