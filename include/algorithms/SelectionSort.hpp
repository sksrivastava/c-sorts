#pragma once

#include "core/SortAlgorithm.hpp"

namespace csorts::algorithms {

template <typename T>
class SelectionSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Selection Sort"; }
    std::string timeComplexity() const override { return "O(n^2)"; }
    std::string spaceComplexity() const override { return "O(1)"; }

protected:
    void sort(std::vector<T>& data) override {
        const std::size_t n = data.size();
        for (std::size_t i = 0; i < n; ++i) {
            std::size_t minIndex = i;
            for (std::size_t j = i + 1; j < n; ++j) {
                if (data[j] < data[minIndex]) {
                    minIndex = j;
                }
            }
            if (minIndex != i) {
                std::swap(data[i], data[minIndex]);
            }
        }
    }
};

}  // namespace csorts::algorithms
