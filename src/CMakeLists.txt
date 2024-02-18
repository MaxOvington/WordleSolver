project(WordleSolver)

add_library(graph graph.cpp process.cpp entropy.cpp)

find_package(OpenMP)
if (OpenMP_CXX_FOUND)
    target_link_libraries(graph PUBLIC OpenMP::OpenMP_CXX)
endif()

target_include_directories(graph
    PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/../include)
