#include "graph/graph.h"
#include <iostream>
#include <filesystem>
#include <fstream>

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
        std::cout << "[" << wordlist_[i] << "] ";
    }
    std::cout << "\n";
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

    add_word(word);

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
            node_list_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL].push_back(i);
            //adjacency matrix
            matrix_[i][wordlist_.size() - 1 + NUM_LETTERS_TOTAL] = 1;
            matrix_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL][i] = 1;
        } 
    }

    for (int i = 0; i < word.size(); i++) {
        //add positive connection for *1..5 letters
        node_list_[((i + 1) * 26) + (word[i] - 97)].push_back(wordlist_.size() - 1 + NUM_LETTERS_TOTAL);
        node_list_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL].push_back(((i + 1) * 26) + (word[i] - 97));
        //adjacency matrix
        matrix_[((i + 1) * 26) + (word[i] - 97)][wordlist_.size() - 1 + NUM_LETTERS_TOTAL] = 1;
        matrix_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL][((i + 1) * 26) + (word[i] - 97)] = 1; 
    }

    //add remaining negative connections
    for (int i = 0; i < NUM_LETTERS; i++) {
        //if node was not added to graph, add to negative version
        if (node_list_[i].size() == 0 || 
        node_list_[i][node_list_[i].size() - 1] != wordlist_.size() - 1 + NUM_LETTERS_TOTAL) {
            node_list_[i + NUM_LETTERS].push_back(wordlist_.size() - 1 + NUM_LETTERS_TOTAL); 
            node_list_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL].push_back(i + NUM_LETTERS);
            //adjacency matrix
            matrix_[i + NUM_LETTERS][wordlist_.size() - 1 + NUM_LETTERS_TOTAL] = 1;
            matrix_[wordlist_.size() - 1 + NUM_LETTERS_TOTAL][i + NUM_LETTERS] = 1; 
        }
    }

    //std::cout << "Added word: [" << word << "]\n";
}

auto Graph::add_word(std::string s) -> void {
    //add to wordlist if not in wordlist
    if (!binarySearch(s, 0, wordlist_.size() - 1)) {
        wordlist_.push_back(s);
        node_list_.push_back(std::vector<int>());
    }
}

auto Graph::process_words() -> int {

    std::filesystem::path p = std::filesystem::current_path();
    p = p.parent_path().parent_path() / "src/words.txt";

    std::string filename = "words.txt";
    std::string line;
    std::ifstream fp("/home/MCMO/Documents/CODE/WordleSolver/src/words.txt", std::ios::binary);
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