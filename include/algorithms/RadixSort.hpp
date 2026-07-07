#pragma once

#include "core/SortAlgorithm.hpp"

#include <algorithm>
#include <cmath>
#include <limits>

namespace csorts::algorithms {

class RadixSort : public core::SortAlgorithm<int> {
public:
    std::string name() const override { return "Radix Sort"; }
    std::string timeComplexity() const override { return "O(d * (n + k))"; }
    std::string spaceComplexity() const override { return "O(n + k)"; }

protected:
    void sort(std::vector<int>& data) override {
        if (data.empty()) {
            return;
        }

        const auto [minIt, maxIt] = std::minmax_element(data.begin(), data.end());
        const int minValue = *minIt;
        const int maxValue = *maxIt;

        if (minValue < 0) {
            std::vector<int> negatives;
            std::vector<int> nonNegatives;
            negatives.reserve(data.size());
            nonNegatives.reserve(data.size());

            for (const int value : data) {
                if (value < 0) {
                    negatives.push_back(value);
                } else {
                    nonNegatives.push_back(value);
                }
            }

            radixSortNonNegative(negatives, true);
            radixSortNonNegative(nonNegatives, false);

            std::size_t index = 0;
            for (const int value : negatives) {
                data[index++] = value;
            }
            for (const int value : nonNegatives) {
                data[index++] = value;
            }
            return;
        }

        radixSortNonNegative(data, false);
        (void)maxValue;
    }

private:
    void radixSortNonNegative(std::vector<int>& data, bool isNegative) {
        if (data.empty()) {
            return;
        }

        const int maxValue =
            isNegative ? -(*std::min_element(data.begin(), data.end()))
                       : *std::max_element(data.begin(), data.end());
        const int digits = maxValue == 0 ? 1 : static_cast<int>(std::log10(maxValue)) + 1;

        std::vector<int> output(data.size());
        constexpr int base = 10;

        for (int digit = 0; digit < digits; ++digit) {
            const int exp = static_cast<int>(std::pow(base, digit));
            std::vector<int> counts(base, 0);

            for (const int value : data) {
                const int key = (std::abs(value) / exp) % base;
                ++counts[key];
            }

            for (int i = 1; i < base; ++i) {
                counts[i] += counts[i - 1];
            }

            for (int i = static_cast<int>(data.size()) - 1; i >= 0; --i) {
                const int value = data[static_cast<std::size_t>(i)];
                const int key = (std::abs(value) / exp) % base;
                output[static_cast<std::size_t>(--counts[key])] = value;
            }

            data = output;
        }

        if (isNegative) {
            std::reverse(data.begin(), data.end());
        }
    }
};

}  // namespace csorts::algorithms
