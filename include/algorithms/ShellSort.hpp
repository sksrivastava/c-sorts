#pragma once

#include "core/SortAlgorithm.hpp"

namespace csorts::algorithms {

template <typename T>
class ShellSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Shell Sort"; }
    std::string timeComplexity() const override { return "O(n log^2 n) to O(n^(3/2))"; }
    std::string spaceComplexity() const override { return "O(1)"; }

protected:
    void sort(std::vector<T>& data) override {
        const std::size_t n = data.size();
        for (std::size_t gap = n / 2; gap > 0; gap /= 2) {
            for (std::size_t i = gap; i < n; ++i) {
                T temp = data[i];
                std::size_t j = i;
                while (j >= gap && data[j - gap] > temp) {
                    data[j] = data[j - gap];
                    j -= gap;
                }
                data[j] = temp;
            }
        }
    }
};

}  // namespace csorts::algorithms
