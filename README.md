# c-sorts

An interactive C++ application to explore major sorting algorithms. Select an algorithm, provide numbers or strings as input, and view the sorted output along with time complexity, space complexity, and measured runtime.

## Features

- **9 sorting algorithms** for integers: Bubble, Selection, Insertion, Shell, Merge, Quick, Heap, Counting, and Radix Sort
- **7 comparison-based algorithms** for strings: Bubble, Selection, Insertion, Shell, Merge, Quick, and Heap Sort
- **Measured response time** using high-resolution timers
- **Documented complexity** for each algorithm (time and space)
- **Modular OOP design** with a shared `SortAlgorithm` interface and per-algorithm implementations

## Project Structure

```
c-sorts/
├── CMakeLists.txt
├── include/
│   ├── algorithms/       # Individual sort algorithm classes
│   ├── core/             # Base interfaces, timer, result types
│   ├── input/            # Input parsing utilities
│   └── ui/               # Menu and result display
└── src/
    └── main.cpp          # Application entry point
```

## Build

```bash
cmake -S . -B build
cmake --build build
```

## Run

```bash
./build/c-sorts
```

## Usage

1. Choose input type: **Numbers** or **Strings**
2. Pick a sorting algorithm from the menu
3. Enter values separated by spaces or commas
4. Review the sorted output, complexity info, and response time

### Example (integers)

```
Select input type:
  1. Numbers (integers)
  2. Strings
Enter choice: 1

Available sorting algorithms:
  1. Bubble Sort | Time: O(n^2) average and worst | Space: O(1)
  ...

Select algorithm (1-9): 5

Enter values separated by spaces or commas:
Example: 42 -3 17 0 8
> 42 -3 17 0 8

========== Sort Result ==========
Algorithm       : Merge Sort
Time Complexity : O(n log n)
Space Complexity: O(n)
Response Time   : 0.003 ms
Sorted Output   : -3, 0, 8, 17, 42
=================================
```

## Requirements

- C++17 or later
- CMake 3.16+

## License

MIT
