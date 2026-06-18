#include "frogpilot/ui/screenrecorder/recorder_engine.h"

#include <cerrno>
#include <chrono>
#include <vector>

#include <fcntl.h>
#include <sys/file.h>
#include <sys/statvfs.h>
#include <unistd.h>

#include <QDateTime>
#include <QDir>
#include <QFile>

#include "common/swaglog.h"
#include "common/timing.h"
#include "common/util.h"

#include "third_party/libyuv/include/libyuv.h"

namespace {
const QString RECORDINGS_DIR = "/data/media/screen_recordings";
const QString RECORDINGS_LOCK = "/data/media/screen_recordings.lock";
constexpr uint64_t MAX_SEGMENT_NS = 5ULL * 60 * 1000000000ULL;
constexpr uint64_t MIN_FREE_SPACE_BYTES = 6ULL << 30;
}

std::atomic<bool> RecorderEngine::engine_active{false};

RecorderEngine::RecorderEngine(int width, int height, int fps, int bitrate) : bitrate(bitrate), fps(fps), height(height), width(width) {}

RecorderEngine::~RecorderEngine() {
  stop();
}

bool RecorderEngine::acquire_recordings_lock() {
  const QByteArray lock_path = QFile::encodeName(RECORDINGS_LOCK);
  recordings_lock_fd = ::open(lock_path.constData(), O_RDWR | O_CREAT | O_CLOEXEC | O_NOFOLLOW, 0664);
  if (recordings_lock_fd < 0 || ::flock(recordings_lock_fd, LOCK_SH | LOCK_NB) != 0) {
    LOGE("screenrecorder: could not retain the recording-session lock (errno %d)", errno);
    release_recordings_lock();
    return false;
  }
  return true;
}

bool RecorderEngine::open_segment() {
  struct statvfs vfs;
  if (statvfs(RECORDINGS_DIR.toStdString().c_str(), &vfs) != 0) {
    LOGE("screenrecorder: could not inspect free space (errno %d)", errno);
    return false;
  }

  uint64_t free_bytes = (uint64_t)vfs.f_bavail * vfs.f_frsize;
  if (free_bytes < MIN_FREE_SPACE_BYTES) {
    LOGE("screenrecorder: not enough free space to record (%llu MB free)",
         (unsigned long long)(free_bytes >> 20));
    return false;
  }

  encoder = std::make_unique<ScreenEncoder>(width, height, fps, bitrate);

  if (!encoder->open(segment_path())) {
    encoder.reset();
    return false;
  }

  segment_start_ns = nanos_since_boot();

  return true;
}

void RecorderEngine::release_recordings_lock() {
  if (recordings_lock_fd >= 0) {
    ::close(recordings_lock_fd);
    recordings_lock_fd = -1;
  }
}

std::string RecorderEngine::segment_path() const {
  QString name = QDateTime::currentDateTime().toString("MMMM_dd_yyyy-hh-mm-ssAP") + ".mp4";
  return (RECORDINGS_DIR + "/" + name).toStdString();
}

bool RecorderEngine::start() {
  if (recording) {
    return true;
  }

  if (worker.joinable()) {
    if (!worker_finished) {
      return false;
    }
    worker.join();
  }

  bool inactive = false;
  if (!engine_active.compare_exchange_strong(inactive, true)) {
    LOGE("screenrecorder: another recorder is already running");
    return false;
  }

  QDir().mkpath(RECORDINGS_DIR);
  if (!open_segment()) {
    LOGE("screenrecorder: failed to start encoder");
    engine_active = false;
    return false;
  }
  if (!acquire_recordings_lock()) {
    encoder.reset();
    engine_active = false;
    return false;
  }

  worker_finished = false;
  recording = true;

  worker = std::thread(&RecorderEngine::worker_loop, this);

  return true;
}

bool RecorderEngine::can_accept_frame() const {
  if (!recording) {
    return false;
  }

  std::lock_guard<std::mutex> lk(q_mutex);
  return queue.size() < MAX_QUEUE;
}

void RecorderEngine::request_stop() {
  recording = false;
  q_cv.notify_all();
}

void RecorderEngine::stop() {
  request_stop();

  if (worker.joinable()) {
    worker.join();
  }
  release_recordings_lock();

  {
    std::lock_guard<std::mutex> lk(q_mutex);
    queue.clear();
  }
}

void RecorderEngine::submit_frame(QImage &&frame, uint64_t ts_ns) {
  if (!recording) {
    return;
  }

  {
    std::lock_guard<std::mutex> lk(q_mutex);
    if (queue.size() >= MAX_QUEUE) {
      queue.pop_front();
    }
    queue.push_back({std::move(frame), ts_ns});
  }
  q_cv.notify_one();
}

void RecorderEngine::worker_loop() {
  util::set_thread_name("sr-capture");

  const int uv_height = (height + 1) / 2;
  const size_t y_size = static_cast<size_t>(width) * height;
  std::vector<uint8_t> blend_frame(y_size + static_cast<size_t>(width) * uv_height);
  std::vector<uint8_t> current_frame(blend_frame.size());
  std::vector<uint8_t> previous_frame(blend_frame.size());
  bool has_previous_frame = false;
  uint64_t prev_ts = 0;

  while (true) {
    CapturedFrame cf;
    {
      std::unique_lock<std::mutex> lk(q_mutex);
      q_cv.wait_for(lk, std::chrono::milliseconds(100),
                    [this] { return !queue.empty() || !recording; });

      if (queue.empty()) {
        if (!recording) {
          break;
        }
        continue;
      }

      cf = std::move(queue.front());
      queue.pop_front();
    }

    if (recording && nanos_since_boot() - segment_start_ns > MAX_SEGMENT_NS) {
      encoder.reset();

      if (!open_segment()) {
        LOGE("screenrecorder: segment rotation failed, stopping");
        recording = false;
        break;
      }

      has_previous_frame = false;
      prev_ts = 0;
    }

    if (!encoder || !encoder->ok()) {
      recording = false;
      break;
    }

    if (cf.image.format() != QImage::Format_RGB32) {
      cf.image = cf.image.convertToFormat(QImage::Format_RGB32);
    }

    if (cf.image.width() != width || cf.image.height() != height) {
      if (!size_warned) {
        LOGW("screenrecorder: grabbed frame %dx%d != configured %dx%d, rescaling",
             cf.image.width(), cf.image.height(), width, height);
        size_warned = true;
      }
      cf.image = cf.image.scaled(width, height, Qt::IgnoreAspectRatio, Qt::FastTransformation);
    }

    libyuv::ARGBToNV12(cf.image.constBits(), cf.image.bytesPerLine(),
                       current_frame.data(), width, current_frame.data() + y_size, width,
                       width, height);

    if (has_previous_frame && encoder->can_encode_pair()) {
      uint64_t mid_ts = prev_ts + (cf.ts_ns - prev_ts) / 2;
      libyuv::InterpolatePlane(previous_frame.data(), width, current_frame.data(), width,
                               blend_frame.data(), width, width, height, 128);
      libyuv::InterpolatePlane(previous_frame.data() + y_size, width, current_frame.data() + y_size, width,
                               blend_frame.data() + y_size, width, width, uv_height, 128);
      encoder->encode_frame(blend_frame.data(), width, mid_ts);
    }
    if (encoder->encode_frame(current_frame.data(), width, cf.ts_ns)) {
      previous_frame.swap(current_frame);
      has_previous_frame = true;
      prev_ts = cf.ts_ns;
    }
  }

  {
    std::lock_guard<std::mutex> lk(q_mutex);
    queue.clear();
  }
  encoder.reset();
  release_recordings_lock();
  engine_active = false;
  worker_finished = true;
}
