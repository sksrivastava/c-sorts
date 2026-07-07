#pragma once

#include "core/SortAlgorithm.hpp"

namespace csorts::algorithms {

template <typename T>
class HeapSort : public core::SortAlgorithm<T> {
public:
    std::string name() const override { return "Heap Sort"; }
    std::string timeComplexity() const override { return "O(n log n)"; }
    std::string spaceComplexity() const override { return "O(1)"; }

protected:
    void sort(std::vector<T>& data) override {
        if (data.size() < 2) {
            return;
        }

        for (int i = static_cast<int>(data.size() / 2) - 1; i >= 0; --i) {
            heapify(data, data.size(), static_cast<std::size_t>(i));
        }

        for (std::size_t end = data.size(); end > 1; --end) {
            std::swap(data[0], data[end - 1]);
            heapify(data, end - 1, 0);
        }
    }

private:
    void heapify(std::vector<T>& data, std::size_t heapSize, std::size_t root) {
        std::size_t largest = root;
        const std::size_t left = 2 * root + 1;
        const std::size_t right = 2 * root + 2;

        if (left < heapSize && data[left] > data[largest]) {
            largest = left;
        }
        if (right < heapSize && data[right] > data[largest]) {
            largest = right;
        }
        if (largest != root) {
            std::swap(data[root], data[largest]);
            heapify(data, heapSize, largest);
        }
    }
};

}  // namespace csorts::algorithms
