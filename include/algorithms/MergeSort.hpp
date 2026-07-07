#pragma once

#include "core/SortAlgorithm.hpp"

namespace csorts::algorithms {

template <typename T>
class MergeSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Merge Sort"; }
    std::string timeComplexity() const override { return "O(n log n)"; }
    std::string spaceComplexity() const override { return "O(n)"; }

protected:
    void sort(std::vector<T>& data) override {
        if (data.size() < 2) {
            return;
        }
        std::vector<T> buffer(data.size());
        mergeSort(data, buffer, 0, data.size());
    }

private:
    void mergeSort(std::vector<T>& data, std::vector<T>& buffer, std::size_t left,
                   std::size_t right) {
        if (right - left <= 1) {
            return;
        }

        const std::size_t mid = left + (right - left) / 2;
        mergeSort(data, buffer, left, mid);
        mergeSort(data, buffer, mid, right);
        merge(data, buffer, left, mid, right);
    }

    void merge(std::vector<T>& data, std::vector<T>& buffer, std::size_t left,
               std::size_t mid, std::size_t right) {
        std::size_t i = left;
        std::size_t j = mid;
        std::size_t k = left;

        while (i < mid && j < right) {
            if (data[i] <= data[j]) {
                buffer[k++] = data[i++];
            } else {
                buffer[k++] = data[j++];
            }
        }

        while (i < mid) {
            buffer[k++] = data[i++];
        }
        while (j < right) {
            buffer[k++] = data[j++];
        }

        for (std::size_t index = left; index < right; ++index) {
            data[index] = buffer[index];
        }
    }
};

}  // namespace csorts::algorithms
