#pragma once

#include "core/SortAlgorithm.hpp"

#include <algorithm>
#include <limits>

namespace csorts::algorithms {

class CountingSort : public core::SortAlgorithm<int> {
public:
    std::string name() const override { return "Counting Sort"; }
    std::string timeComplexity() const override { return "O(n + k)"; }
    std::string spaceComplexity() const override { return "O(k)"; }

protected:
    void sort(std::vector<int>& data) override {
        if (data.empty()) {
            return;
        }

        const auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
        const int minValue = *minIt;
        const int maxValue = *maxIt;
        const std::size_t range = static_cast<std::size_t>(maxValue - minValue) + 1;

        std::vector<std::size_t> counts(range, 0);
        for (const int value : data) {
            ++counts[static_cast<std::size_t>(value - minValue)];
        }

        std::size_t index = 0;
        for (std::size_t i = 0; i < range; ++i) {
            while (counts[i]-- > 0) {
                data[index++] = static_cast<int>(i) + minValue;
            }
        }
    }
};

}  // namespace csorts::algorithms
