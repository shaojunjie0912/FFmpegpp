#pragma once

#include <memory>

extern "C" {
#include <libavcodec/avcodec.h>
}

namespace ffmpegpp {

struct AVFrameDeleter {
    void operator()(AVFrame* frame) const {
        if (frame) {
            av_frame_free(&frame);
        }
    }
};

class Frame {
private:
    std::unique_ptr<AVFrame, AVFrameDeleter> frame_;

public:
    Frame() : frame_(av_frame_alloc(), AVFrameDeleter{}) {}

    ~Frame() = default;

    // AVFrame* get() { return frame_.get(); }
};

}  // namespace ffmpegpp