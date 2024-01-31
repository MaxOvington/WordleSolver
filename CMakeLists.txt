cmake_minimum_required(VERSION 3.15)
project(WordleSolver)

add_subdirectory(include)
add_subdirectory(src)

option(BUILD_EXAMPLES "Whether or not build examples" ON)

if (BUILD_EXAMPLES)
    message("Building example executable.. ")
    add_subdirectory(example)
endif()
