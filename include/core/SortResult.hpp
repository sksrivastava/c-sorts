#pragma once

#include <chrono>
#include <string>
#include <vector>

namespace csorts::core {

template <typename T>
struct SortResult {
    std::vector<T> sortedData;
    std::string algorithmName;
    std::string timeComplexity;
    std::string spaceComplexity;
    std::chrono::duration<double, std::milli> elapsedTime;
};

}  // namespace csorts::core
