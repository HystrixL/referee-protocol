#pragma once

#include <referee_protocol/crc.h>
#include <referee_protocol/data.h>
#include <array>
#include <cstring>
#include <optional>
namespace rp {

constexpr unsigned char FRAME_HEADER_SOF = 0xA5;

struct [[gnu::packed]] FrameHeader {
   private:
    inline static unsigned char seq_temp{};
    unsigned char SOF_{FRAME_HEADER_SOF};
    unsigned short data_length_;
    unsigned char seq_{seq_temp++};
    unsigned char CRC8_;
    static constexpr unsigned int SIZE = sizeof(SOF_) + sizeof(data_length_) + sizeof(seq_) + sizeof(CRC8_);

   public:
    explicit FrameHeader(unsigned short data_length) {
        data_length_ = data_length;
        CRC8_ = rp::crc::get_CRC8_check_sum(reinterpret_cast<unsigned char*>(this), SIZE - sizeof(CRC8_), 0xff);
    }
    [[nodiscard]] auto GetSof() const { return SOF_; }
    [[nodiscard]] auto GetDataLength() const { return data_length_; }
    [[nodiscard]] auto GetSeq() const { return seq_; }
    [[nodiscard]] auto GetCrc8() const { return CRC8_; }
};
template <typename T>
concept RefereeProtocolData = requires(T) {
    T::CMD_ID;
    std::is_base_of_v<IData<T::CMD_ID>, T>;
};
template <RefereeProtocolData T>
struct [[gnu::packed]] Frame {
    FrameHeader frame_header{sizeof(T)};
    const unsigned char cmd_id{T::CMD_ID};
    T data;
    unsigned short frame_tail{};
    static constexpr unsigned int SIZE = sizeof(frame_header) + sizeof(cmd_id) + sizeof(data) + sizeof(frame_tail);

    explicit Frame(T d) {
        data = d;
        frame_tail =
            rp::crc::get_CRC16_check_sum(reinterpret_cast<unsigned char*>(this), SIZE - sizeof(frame_tail), 0xffff);
    }
    Frame() = default;

    auto ToBytes() const {
        std::array<unsigned char, SIZE> buffer{};
        std::memcpy(buffer.data(), this, SIZE);
        return buffer;
    }

    static std::optional<Frame> FromBytes(std::array<unsigned char, SIZE> buffer) {
        Frame frame{};
        std::memcpy(&frame, buffer.data(), SIZE);
        if (rp::crc::verify_CRC8_check_sum(reinterpret_cast<unsigned char*>(&frame.frame_header),
                                           sizeof(FrameHeader)) &&
            rp::crc::verify_CRC16_check_sum(reinterpret_cast<unsigned char*>(&frame), SIZE))
            return std::optional<Frame>(frame);
        return std::nullopt;
    }

    [[nodiscard]] auto GetFrameHeader() const { return frame_header; }
    [[nodiscard]] auto GetCmdId() const { return cmd_id; }
    [[nodiscard]] auto GetData() const { return data; }
    [[nodiscard]] auto GetFrameTail() const { return frame_tail; }
};
}  // namespace rp
