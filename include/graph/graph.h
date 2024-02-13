#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#define NUM_LETTERS_TOTAL 312 //156 is pos, 156 negative
#define NUM_LETTERS 156
#define ALPHABET_SIZE 26

class Graph {
    public: 
        Graph(int val) {
            auto m = std::vector<std::vector<int>> (NUM_LETTERS_TOTAL, 
            std::vector<int> (val + NUM_LETTERS_TOTAL));
            matrix_ = m;
            int ret = process_words();
            auto r = std::vector<int> (val, 0);
            word_rounds_ = r;
            if (ret < 0) std::exit(EXIT_FAILURE);
        }
        auto add_edge(std::string word) -> void;
        auto print_words() -> void;
        auto print_graph_list() -> void;
        auto search_match(std::vector<int> vec, int round) -> void;
        auto get_word_size() -> int;

    private:
        int val_;
        std::vector<int> word_rounds_;
        std::vector<std::vector<int>> node_list_ {NUM_LETTERS_TOTAL};
        std::vector<std::string> wordlist_;
        std::vector<std::vector<int>> matrix_;
        auto binarySearch(std::string word, int lo, int hi) -> bool;
        auto process_words() -> int;
        auto add_word(std::string s) -> void;
};

