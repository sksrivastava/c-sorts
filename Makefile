CXX ?= g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -Iinclude
TARGET = build/c-sorts
SRC = src/main.cpp

.PHONY: all clean run

all: $(TARGET)

$(TARGET): $(SRC) | build
	$(CXX) $(CXXFLAGS) -o $@ $(SRC)

build:
	mkdir -p build

run: all
	./$(TARGET)

clean:
	rm -rf build
