project(WordleSolver)


add_library(graph graph.cpp process.cpp entropy.cpp)
target_include_directories(graph
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)