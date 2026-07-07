#pragma once

#include "core/SortAlgorithm.hpp"

namespace csorts::algorithms {

template <typename T>
class InsertionSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Insertion Sort"; }
    std::string timeComplexity() const override { return "O(n^2) worst, O(n) best"; }
    std::string spaceComplexity() const override { return "O(1)"; }

protected:
    void sort(std::vector<T>& data) override {
        for (std::size_t i = 1; i < data.size(); ++i) {
            T key = data[i];
            std::size_t j = i;
            while (j > 0 && data[j - 1] > key) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = key;
        }
    }
};

}  // namespace csorts::algorithms
