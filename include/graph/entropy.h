#pragma once
#include <iostream>
#include "graph/process.h"
#include "graph/graph.h"
#include <string>
#include <fstream>
#include <mutex>

double entropy(int total, int word, std::vector<int> universe, Graph &g);

double do_entropy(int total, std::vector<int> input, int word, std::vector<int> universe, Graph &g, int index, int type);

bool letter_is_present(char c);

void print_loading_bar(bool &calc, int &cnt, int total, std::mutex &mtx);

int generate_word_match(std::string &curr, std::string &target);

double do_entropy2(int total, int word, std::vector<int> universe, Graph &g);

std::vector<std::pair<double, std::pair<double, int>>> generate_entropy(int total, std::vector<int> &universe, Graph &g);