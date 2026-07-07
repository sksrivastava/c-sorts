#pragma once

#include "core/SortResult.hpp"

#include <iostream>
#include <string>
#include <type_traits>

namespace csorts::ui {

template <typename T>
class ResultPrinter {
public:
    static void print(const core::SortResult<T>& result) {
        std::cout << "\n========== Sort Result ==========\n";
        std::cout << "Algorithm       : " << result.algorithmName << '\n';
        std::cout << "Time Complexity : " << result.timeComplexity << '\n';
        std::cout << "Space Complexity: " << result.spaceComplexity << '\n';
        std::cout << "Response Time   : " << result.elapsedTime.count() << " ms\n";
        std::cout << "Sorted Output   : ";

        for (std::size_t i = 0; i < result.sortedData.size(); ++i) {
            if (i > 0) {
                std::cout << ", ";
            }
            printValue(result.sortedData[i]);
        }
        std::cout << "\n=================================\n";
    }

private:
    static void printValue(const T& value) {
        if constexpr (std::is_same_v<T, std::string>) {
            std::cout << '"' << value << '"';
        } else {
            std::cout << value;
        }
    }
};

}  // namespace csorts::ui
