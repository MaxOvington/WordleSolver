#pragma once
#include <vector>
#include <iostream>
#include <string>
#define NUM_LETTERS_TOTAL 312 //156 is pos, 156 negative
#define NUM_LETTERS 156
#define ALPHABET_SIZE 26

class Graph {
    public: 
        Graph(int const val);
        auto get_val() -> int const&;
        auto set_val(int x) -> void;
        
        //TODO
        auto add_edge(std::string word) -> void;

        //TODO
        auto print_words() -> void;
        auto print_graph_list() -> void;

    private:
        int val_;
        std::vector<std::vector<int>> node_list_ {NUM_LETTERS_TOTAL};
        std::vector<std::string> wordlist_;
        //TODO add matrix representation

        auto binarySearch(std::string word, int lo, int hi) -> bool;
};

//constructor defined outside of scope, scoped by classname
Graph::Graph(int const val) {
    val_ = val;
}

auto Graph::print_words() -> void {
    std::cout << "Graph contains the following words: \n";
    for (int i = 0; i < wordlist_.size(); i++) {
        std::cout << wordlist_[i] << "\n";
    }
}

auto Graph::print_graph_list() -> void {
    for (int i = 0; i < node_list_.size(); i++) {
        std::cout << "Index [" << i << "] -> ";
        for (int j = 0; j < node_list_[i].size(); j++) {
            std::cout << node_list_[i][j] << " ";
        }
        std:: cout << "\n";
    }
}

auto Graph::binarySearch(std::string word, int lo, int hi) -> bool {
    //binary search case where nothing left
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (wordlist_[mid] == word) {
            return true;
        } else if (wordlist_[mid] > word) {
            return binarySearch(word, lo, mid - 1);
        } else if (wordlist_[mid] < word) {
            return binarySearch(word, mid + 1, hi);
        }
    }
    return false;
}

auto Graph::add_edge(std::string word) -> void {

    //add to wordlist if not in wordlist
    if (!binarySearch(word, 0, wordlist_.size() - 1)) {
        wordlist_.push_back(word);
        node_list_.push_back(std::vector<int>());
    }

    //remove duplicate words
    int alphabet[ALPHABET_SIZE] = {0};
    for (int i = 0; i < word.size(); i++) {
        alphabet[word[i] - 97] = 1;
    }

    for (int i = 0; i < ALPHABET_SIZE; i++) {
        std::cout << alphabet[i] << " ";
    }
    std::cout << "\n";

    //add edge for words
    //add for *0
    for (int i = 0; i < ALPHABET_SIZE; i++) {   
        //add positive connection 
        if (alphabet[i]){
            node_list_[i].push_back(NUM_LETTERS_TOTAL + wordlist_.size() - 1); 
            node_list_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL].push_back(i);
        } 
    }

    std::cout << "TEST\n";

    for (int i = 0; i < word.size(); i++) {
        //add positive connection for *1..5 letters
        node_list_[((i + 1) * 26) + (word[i] - 97)].push_back(wordlist_.size() - 1 + NUM_LETTERS_TOTAL);
        node_list_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL].push_back(((i + 1) * 26) + (word[i] - 97));
        //std::cout << "added edge to " << ((i + 2) * (word[i] - 97)) << "\n";
        //std::cout << word[i] << " " << (word[i] - 97) << " " << (i + 2) << "\n";
    }

    //add remaining negative connections
    for (int i = 0; i < NUM_LETTERS; i++) {
        //if node was not added to graph, add to negative version
        if (node_list_[i].size() == 0 || 
        node_list_[i][node_list_[i].size() - 1] != wordlist_.size() - 1 + NUM_LETTERS_TOTAL) {
            //std::cout << "Adding negative for " << i << "..\n";
            node_list_[i + NUM_LETTERS].push_back(wordlist_.size() - 1 + NUM_LETTERS_TOTAL); 
            node_list_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL].push_back(i + NUM_LETTERS);
        }
    }

    //print_graph_list();

    std::cout << "Added word: [" << word << "]\n";
}

auto Graph::get_val() -> int const& {
    return val_;
}

auto Graph::set_val(int x) -> void {
    val_ = x;
}