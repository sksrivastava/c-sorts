#pragma once

#include "core/SortAlgorithm.hpp"

namespace csorts::algorithms {

template <typename T>
class BubbleSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Bubble Sort"; }
    std::string timeComplexity() const override { return "O(n^2) average and worst"; }
    std::string spaceComplexity() const override { return "O(1)"; }

protected:
    void sort(std::vector<T>& data) override {
        const std::size_t n = data.size();
        for (std::size_t i = 0; i < n; ++i) {
            bool swapped = false;
            for (std::size_t j = 0; j + 1 < n - i; ++j) {
                if (data[j + 1] < data[j]) {
                    std::swap(data[j], data[j + 1]);
                    swapped = true;
                }
            }
            if (!swapped) {
                break;
            }
        }
    }
};

}  // namespace csorts::algorithms
