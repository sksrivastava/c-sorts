#pragma once

#include "core/SortResult.hpp"
#include "core/Timer.hpp"

#include <string>
#include <vector>

namespace csorts::core {

template <typename T>
class SortAlgorithm {
public:
    virtual ~SortAlgorithm() = default;

    virtual std::string name() const = 0;
    virtual std::string timeComplexity() const = 0;
    virtual std::string spaceComplexity() const = 0;

    SortResult<T> execute(std::vector<T> data) {
        Timer timer;
        timer.start();
        sort(data);
        const auto elapsed = timer.stop();

        return SortResult<T>{
            .sortedData = std::move(data),
            .algorithmName = name(),
            .timeComplexity = timeComplexity(),
            .spaceComplexity = spaceComplexity(),
            .elapsedTime = elapsed,
        };
    }

protected:
    virtual void sort(std::vector<T>& data) = 0;
};

}  // namespace csorts::core
