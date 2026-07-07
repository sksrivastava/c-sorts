#pragma once

#include "algorithms/AlgorithmRegistry.hpp"
#include "core/SortAlgorithm.hpp"
#include "input/InputParser.hpp"
#include "ui/ResultPrinter.hpp"

#include <iostream>
#include <limits>
#include <memory>
#include <string>
#include <vector>

namespace csorts::ui {

enum class DataType { Integer, String };

class Menu {
public:
    void run() {
        printWelcome();
        bool running = true;

        while (running) {
            try {
                const DataType dataType = selectDataType();
                if (dataType == DataType::Integer) {
                    runIntegerFlow();
                } else {
                    runStringFlow();
                }
            } catch (const std::exception& ex) {
                std::cout << "\nError: " << ex.what() << '\n';
            }

            running = promptContinue();
        }

        std::cout << "\nThank you for using c-sorts!\n";
    }

private:
    static void printWelcome() {
        std::cout << "========================================\n";
        std::cout << "          C-Sorts: Sorting Lab          \n";
        std::cout << "========================================\n";
        std::cout << "Compare major sorting algorithms with\n";
        std::cout << "complexity info and measured runtime.\n\n";
    }

    static void runIntegerFlow() {
        const auto algorithms = algorithms::AlgorithmRegistry<int>::getAll();
        displayAlgorithms(algorithms);
        const std::size_t algorithmIndex = selectAlgorithm(algorithms.size());
        const std::string rawInput = readInput(DataType::Integer);
        runSort<int>(algorithms[algorithmIndex], rawInput);
    }

    static void runStringFlow() {
        const auto algorithms = algorithms::AlgorithmRegistry<std::string>::getAll();
        displayAlgorithms(algorithms);
        const std::size_t algorithmIndex = selectAlgorithm(algorithms.size());
        const std::string rawInput = readInput(DataType::String);
        runSort<std::string>(algorithms[algorithmIndex], rawInput);
    }

    static DataType selectDataType() {
        std::cout << "Select input type:\n";
        std::cout << "  1. Numbers (integers)\n";
        std::cout << "  2. Strings\n";
        std::cout << "Enter choice: ";

        const int choice = readIntInRange(1, 2);
        return choice == 1 ? DataType::Integer : DataType::String;
    }

    template <typename T>
    static void displayAlgorithms(const std::vector<std::unique_ptr<core::SortAlgorithm<T>>>& algorithms) {
        std::cout << "\nAvailable sorting algorithms:\n";
        for (std::size_t i = 0; i < algorithms.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << algorithms[i]->name() << " | Time: "
                      << algorithms[i]->timeComplexity()
                      << " | Space: " << algorithms[i]->spaceComplexity() << '\n';
        }
    }

    static std::size_t selectAlgorithm(std::size_t count) {
        std::cout << "\nSelect algorithm (1-" << count << "): ";
        return static_cast<std::size_t>(readIntInRange(1, static_cast<int>(count))) - 1;
    }

    static std::string readInput(const DataType dataType) {
        std::cout << "\nEnter values separated by spaces or commas:\n";
        if (dataType == DataType::Integer) {
            std::cout << "Example: 42 -3 17 0 8\n> ";
        } else {
            std::cout << "Example: zebra apple mango banana\n> ";
        }

        std::string line;
        std::getline(std::cin >> std::ws, line);
        if (line.empty()) {
            throw std::invalid_argument("Input cannot be empty.");
        }
        return line;
    }

    template <typename T>
    static void runSort(const std::unique_ptr<core::SortAlgorithm<T>>& algorithm,
                        const std::string& rawInput) {
        std::vector<T> data;
        if constexpr (std::is_same_v<T, int>) {
            data = input::InputParser::parseIntegers(rawInput);
        } else {
            data = input::InputParser::parseStrings(rawInput);
        }

        const auto result = algorithm->execute(std::move(data));
        ResultPrinter<T>::print(result);
    }

    static int readIntInRange(int minValue, int maxValue) {
        int value = 0;
        while (true) {
            if (!(std::cin >> value)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input. Enter a number: ";
                continue;
            }

            if (value < minValue || value > maxValue) {
                std::cout << "Please enter a value between " << minValue << " and " << maxValue
                          << ": ";
                continue;
            }

            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return value;
        }
    }

    static bool promptContinue() {
        std::cout << "\nSort again? (y/n): ";
        std::string answer;
        std::getline(std::cin >> std::ws, answer);
        return !answer.empty() && (answer[0] == 'y' || answer[0] == 'Y');
    }
};

}  // namespace csorts::ui
