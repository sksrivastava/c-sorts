cmake_minimum_required(VERSION 3.16)
project(c-sorts VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(c-sorts
    src/main.cpp
)

target_include_directories(c-sorts PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

if(MSVC)
    target_compile_options(c-sorts PRIVATE /W4 /permissive-)
else()
    target_compile_options(c-sorts PRIVATE -Wall -Wextra -Wpedantic)
endif()
