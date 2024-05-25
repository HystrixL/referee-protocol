
#include <iostream>
#include "data.hpp"
#include "frame.hpp"
#include "referee_protocol.hpp"

int main() {
    rp::GameResult result1{.winner = rp::GameResult::Winner::Blue};
    rp::Frame<rp::GameResult> result_frame1{result1};
    auto bytes1 = result_frame1.ToBytes();
    for (auto&& byte : bytes1) {
        std::cout << " " << std::hex << (int)byte;
    }
    std::cout << std::endl;

    rp::GameResult result2{};
    rp::Frame<rp::GameResult> result_frame2{result2};
    auto bytes2 = result_frame2.ToBytes();
    for (auto&& byte : bytes2) {
        std::cout << " " << std::hex << (int)byte;
    }
    std::cout << std::endl;

    auto result_frame = rp::Frame<rp::GameResult>::FromBytes(bytes1);
    if (result_frame.has_value()) {
        std::cout << (int)result_frame.value().GetData().winner;
    }
}