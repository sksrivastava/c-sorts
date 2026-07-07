#pragma once

#include <chrono>

namespace csorts::core {

class Timer {
public:
    void start() { startTime_ = std::chrono::high_resolution_clock::now(); }

    std::chrono::duration<double, std::milli> stop() {
        const auto endTime = std::chrono::high_resolution_clock::now();
        return endTime - startTime_;
    }

private:
    std::chrono::high_resolution_clock::time_point startTime_;
};

}  // namespace csorts::core
