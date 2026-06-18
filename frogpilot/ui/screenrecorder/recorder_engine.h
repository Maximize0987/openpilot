#pragma once

#include <atomic>
#include <condition_variable>
#include <deque>
#include <memory>
#include <mutex>
#include <string>
#include <thread>

#include <QImage>

#include "frogpilot/ui/screenrecorder/screen_encoder.h"

class RecorderEngine {
public:
  RecorderEngine(int width, int height, int fps, int bitrate);
  ~RecorderEngine();

  bool is_recording() const { return recording; }
  bool stop_complete() const { return worker_finished; }
  bool start();
  bool can_accept_frame() const;
  void request_stop();

  void stop();
  void submit_frame(QImage &&frame, uint64_t ts_ns);

private:
  struct CapturedFrame {
    QImage image;

    uint64_t ts_ns;
  };

  bool acquire_recordings_lock();
  bool open_segment();
  void release_recordings_lock();

  void worker_loop();

  static constexpr size_t MAX_QUEUE = 4;

  static std::atomic<bool> engine_active;

  const int bitrate;
  const int fps;
  const int height;
  const int width;

  uint64_t segment_start_ns = 0;

  bool size_warned = false;

  std::atomic<bool> recording{false};
  std::atomic<bool> worker_finished{true};

  std::condition_variable q_cv;

  std::deque<CapturedFrame> queue;

  mutable std::mutex q_mutex;

  int recordings_lock_fd = -1;

  std::string segment_path() const;

  std::thread worker;

  std::unique_ptr<ScreenEncoder> encoder;
};
