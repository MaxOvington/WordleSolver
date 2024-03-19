#pragma once
#include "graph.h"
#include <string>

#define INPUT_SIZE 10

int translate_input(std::vector<int> &ret, std::vector<std::string> s);

void generate_universe(std::vector<int> &universe, Graph &g);