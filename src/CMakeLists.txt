project(WordleSolver)


add_library(graph graph.cpp process.cpp)
target_include_directories(graph
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)