#pragma once

#include "algorithms/BubbleSort.hpp"
#include "algorithms/CountingSort.hpp"
#include "algorithms/HeapSort.hpp"
#include "algorithms/InsertionSort.hpp"
#include "algorithms/MergeSort.hpp"
#include "algorithms/QuickSort.hpp"
#include "algorithms/RadixSort.hpp"
#include "algorithms/SelectionSort.hpp"
#include "algorithms/ShellSort.hpp"

#include "core/SortAlgorithm.hpp"

#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

namespace csorts::algorithms {

template <typename T>
class AlgorithmRegistry {
public:
    static std::vector<std::unique_ptr<core::SortAlgorithm<T>>> getAll() {
        std::vector<std::unique_ptr<core::SortAlgorithm<T>>> algorithms;
        algorithms.emplace_back(std::make_unique<BubbleSort<T>>());
        algorithms.emplace_back(std::make_unique<SelectionSort<T>>());
        algorithms.emplace_back(std::make_unique<InsertionSort<T>>());
        algorithms.emplace_back(std::make_unique<ShellSort<T>>());
        algorithms.emplace_back(std::make_unique<MergeSort<T>>());
        algorithms.emplace_back(std::make_unique<QuickSort<T>>());
        algorithms.emplace_back(std::make_unique<HeapSort<T>>());

        if constexpr (std::is_same_v<T, int>) {
            algorithms.emplace_back(std::make_unique<CountingSort>());
            algorithms.emplace_back(std::make_unique<RadixSort>());
        }

        return algorithms;
    }

    static core::SortAlgorithm<T>& getByIndex(std::size_t index) {
        static auto algorithms = getAll();
        if (index >= algorithms.size()) {
            throw std::out_of_range("Algorithm index out of range");
        }
        return *algorithms[index];
    }

    static std::size_t count() { return getAll().size(); }
};

}  // namespace csorts::algorithms
