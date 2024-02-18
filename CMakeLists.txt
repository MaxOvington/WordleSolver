cmake_minimum_required(VERSION 3.15)
project(WordleSolver)

set(CMAKE_BUILD_TYPE RelWithDebInfo)
set(CMAKE_CXX_FLAGS "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g -fopenmp -pthread")
add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Whether or not build examples" ON)

if (BUILD_EXAMPLES)
    message("Building example executable.. ")
    add_subdirectory(example)
endif()