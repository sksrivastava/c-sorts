#pragma once

#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>

namespace csorts::input {

class InputParser {
public:
    static std::vector<int> parseIntegers(const std::string& rawInput) {
        const auto tokens = tokenize(rawInput);
        if (tokens.empty()) {
            throw std::invalid_argument("No integer values provided.");
        }

        std::vector<int> values;
        values.reserve(tokens.size());
        for (const auto& token : tokens) {
            try {
                std::size_t consumed = 0;
                const int value = std::stoi(token, &consumed);
                if (consumed != token.size()) {
                    throw std::invalid_argument("Invalid integer token: " + token);
                }
                values.push_back(value);
            } catch (const std::exception&) {
                throw std::invalid_argument("Invalid integer token: " + token);
            }
        }
        return values;
    }

    static std::vector<std::string> parseStrings(const std::string& rawInput) {
        const auto tokens = tokenize(rawInput);
        if (tokens.empty()) {
            throw std::invalid_argument("No string values provided.");
        }
        return tokens;
    }

private:
    static std::vector<std::string> tokenize(const std::string& rawInput) {
        std::vector<std::string> tokens;
        std::stringstream stream(rawInput);
        std::string token;

        while (stream >> token) {
            std::size_t start = 0;
            while (start < token.size() && (token[start] == ',' || token[start] == ';')) {
                ++start;
            }

            std::size_t end = token.size();
            while (end > start && (token[end - 1] == ',' || token[end - 1] == ';')) {
                --end;
            }

            if (start < end) {
                tokens.emplace_back(token.substr(start, end - start));
            }
        }

        return tokens;
    }
};

}  // namespace csorts::input
