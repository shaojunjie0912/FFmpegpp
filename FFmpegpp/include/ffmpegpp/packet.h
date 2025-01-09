#pragma once
#include <memory>

extern "C" {
#include <libavcodec/avcodec.h>
}

namespace ffmpegpp {

// 自定义删除器，负责释放 AVPacket
struct AVPacketDeleter {
    void operator()(AVPacket* packet) const {
        if (packet) {
            av_packet_free(&packet);
        }
    }
};

class Packet {
private:
    std::unique_ptr<AVPacket, AVPacketDeleter> packet_;

public:
    Packet() : packet_(av_packet_alloc(), AVPacketDeleter{}) {}

    ~Packet() = default;

    // AVPacket* get() { return packet_.get(); }

    // void reset() { packet_ = std::unique_ptr<AVPacket, AVPacketDeleter>(av_packet_alloc(), AVPacketDeleter{}); }
};

}  // namespace ffmpegpp