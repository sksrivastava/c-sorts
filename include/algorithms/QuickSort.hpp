#pragma once

#include "core/SortAlgorithm.hpp"

#include <random>

namespace csorts::algorithms {

template <typename T>
class QuickSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Quick Sort"; }
    std::string timeComplexity() const override { return "O(n log n) average, O(n^2) worst"; }
    std::string spaceComplexity() const override { return "O(log n) average"; }

protected:
    void sort(std::vector<T>& data) override {
        if (data.empty()) {
            return;
        }
        quickSort(data, 0, data.size() - 1);
    }

private:
    void quickSort(std::vector<T>& data, std::size_t low, std::size_t high) {
        while (low < high) {
            const std::size_t pivotIndex = partition(data, low, high);
            if (pivotIndex - low < high - pivotIndex) {
                quickSort(data, low, pivotIndex > 0 ? pivotIndex - 1 : 0);
                low = pivotIndex + 1;
            } else {
                quickSort(data, pivotIndex + 1, high);
                high = pivotIndex > 0 ? pivotIndex - 1 : 0;
            }
        }
    }

    std::size_t partition(std::vector<T>& data, std::size_t low, std::size_t high) {
        static thread_local std::mt19937 rng{std::random_device{}()};
        std::uniform_int_distribution<std::size_t> dist(low, high);
        const std::size_t pivotIndex = dist(rng);
        std::swap(data[pivotIndex], data[high]);

        const T& pivot = data[high];
        std::size_t i = low;
        for (std::size_t j = low; j < high; ++j) {
            if (data[j] < pivot) {
                std::swap(data[i], data[j]);
                ++i;
            }
        }
        std::swap(data[i], data[high]);
        return i;
    }
};

}  // namespace csorts::algorithms
