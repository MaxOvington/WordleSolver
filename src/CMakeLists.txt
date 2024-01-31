project(WordleSolver)


add_library(graph test1.cpp)
target_include_directories(graph
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)