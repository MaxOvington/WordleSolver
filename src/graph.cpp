#include "graph/graph.h"
#include <iostream>
#include <filesystem>
#include <fstream>
#include <algorithm>
#include <unistd.h> 
#include <cmath>

auto Graph::print_graph_list() -> void {
    for (int i = 0; i < node_list_.size(); i++) {
        std::cout << "Index [" << i << "] -> ";
        for (int j = 0; j < node_list_[i].size(); j++) {
            std::cout << node_list_[i][j] << " ";
        }
        std:: cout << "\n";
    }
}

auto Graph::print_words() -> void {
    std::cout << "Graph contains the following words: \n";
    for (int i = 0; i < wordlist_.size(); i++) {
        std::cout << "[" << wordlist_[i].first << "] ";
    }
    std::cout << "\n";
}

auto Graph::get_word_size() -> int {
    return wordlist_.size();
}

auto Graph::binarySearch(std::string word, int lo, int hi) -> bool {
    //binary search case where nothing left
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (wordlist_[mid].first == word) {
            return true;
        } else if (wordlist_[mid].first > word) {
            return binarySearch(word, lo, mid - 1);
        } else if (wordlist_[mid].first < word) {
            return binarySearch(word, mid + 1, hi);
        }
    }
    return false;
}


auto Graph::add_edge(std::string line) -> void {

    std::istringstream word_stream(line);
    std::string word;
    long long prob;

    word_stream >> word >> prob;
    add_word(word, prob);

    //remove duplicate words
    int alphabet[ALPHABET_SIZE] = {0};
    for (int i = 0; i < word.size(); i++) {
        alphabet[word[i] - 97] = 1;
    }

    //add edge for words
    //add for *0
    for (int i = 0; i < ALPHABET_SIZE; i++) {   
        //add positive connection 
        if (alphabet[i]){
            node_list_[i].push_back(NUM_LETTERS_TOTAL + wordlist_.size() - 1); 
            matrix_[i][wordlist_.size() - 1 + NUM_LETTERS_TOTAL] = 1;
        } 
    }

    for (int i = 0; i < word.size(); i++) {
        //add positive connection for *1..5 letters
        node_list_[((i + 1) * 26) + (word[i] - 97)].push_back(wordlist_.size() - 1 + NUM_LETTERS_TOTAL);
        matrix_[((i + 1) * 26) + (word[i] - 97)][wordlist_.size() - 1 + NUM_LETTERS_TOTAL] = 1;
    }

    //add remaining negative connections
    for (int i = 0; i < NUM_LETTERS; i++) {
        //if node was not added to graph, add to negative version
        if (node_list_[i].size() == 0 || 
        node_list_[i][node_list_[i].size() - 1] != wordlist_.size() - 1 + NUM_LETTERS_TOTAL) {
            node_list_[i + NUM_LETTERS].push_back(wordlist_.size() - 1 + NUM_LETTERS_TOTAL); 
            matrix_[i + NUM_LETTERS][wordlist_.size() - 1 + NUM_LETTERS_TOTAL] = 1; 
        }
    }
}

auto Graph::add_word(std::string s, long long prob) -> void {
    //add to wordlist if not in wordlist
    if (!binarySearch(s, 0, wordlist_.size() - 1)) {
        //apply sigmoid function here
        double val = 1.0 / (1 + exp(-prob + SIGMOID_CUT_OFF));
        wordlist_.push_back(std::make_pair(s,val));
        active_words_.push_back(wordlist_.size() - 1);
    }
}

auto Graph::process_words() -> int {

    std::filesystem::path p = std::filesystem::current_path();
    p = p.parent_path().parent_path() / "src/dict.txt";

    std::string filename = "dict.txt";
    std::string line;
    std::ifstream fp("/home/MCMO/Documents/CODE/WordleSolver/src/dict.txt", std::ios::binary);
    if (!fp.is_open()) {
        std::cerr << "Could not open the file - '" << filename << "'" << "\n";
        return EXIT_FAILURE;
    }
    while (getline(fp, line)) {
        add_edge(line);
    }
    fp.close();
    return 0;
}

auto Graph::search_match(std::vector<int> vec, std::vector<int> &universe, bool is_first_round) -> std::vector<int> {
    
    //check if all nums are in appropriate range
    auto match = std::vector<int>();
    auto invalid = [](int i) { return (i < 0 || i >= NUM_LETTERS_TOTAL); };
    auto is_invalid = std::find_if(vec.begin(), vec.end(), invalid) != vec.end();
    if (vec.size() > 10 || vec.size() == 0 || is_invalid == true) {
        std::cout << "Error: Invalid input!\n";
        return universe;
    }
    int iter = (is_first_round) ?  node_list_[vec[0]].size() : universe.size();

    for (int i = 0; i < iter; i++) {
        int eval = 1;
        for (int j = 0; j < vec.size(); j++) {
            eval &= (is_first_round) ? (matrix_[vec[j]][node_list_[vec[0]][i]]) : 
            (matrix_[vec[j]][universe[i] + NUM_LETTERS_TOTAL]);
        }
        if (eval) {
            (is_first_round) ? (match.push_back(node_list_[vec[0]][i] - NUM_LETTERS_TOTAL)) : 
            (match.push_back(universe[i]));
        } 
    }
    return match;
}

auto Graph::get_active_wordlist() -> std::vector<int> {
    return active_words_;
}