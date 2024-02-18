#pragma once
#include <iostream>
#include "graph/process.h"
#include "graph/graph.h"
#include <string>
#include <fstream>

double entropy(int total, int word, std::vector<int> universe, Graph &g);

double do_entropy(int total, std::vector<int> input, int word, std::vector<int> universe, Graph &g, int index, int type);

bool letter_is_present(char c);

std::vector<std::pair<int, double>> generate_entropy(int total, std::vector<int> &universe, Graph &g);