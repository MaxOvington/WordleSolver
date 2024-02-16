#include <iostream>
#include "graph/graph.h"
#include "graph/process.h"
#include "graph/entropy.h"
#include <filesystem>
#include <fstream>

int main (void) {
    int num_words = 0;
    std::filesystem::path p = std::filesystem::current_path();
    p = (p.parent_path().parent_path()) / "src/dict.txt";

    std::cout << "Current path is " << p << "\n";

    std::ifstream fp(p); 
    std::string lne;
    while (getline(fp, lne)) {
        if (!lne.empty()) num_words++;
    }
    std::cout << "Lines read: " << num_words << "\n";

    //return 0;

    Graph wordle_graph(num_words);

    auto universe = wordle_graph.get_active_wordlist();

    entropy(num_words, 16331, universe, wordle_graph);
    entropy(num_words, 0, universe, wordle_graph);

    bool is_first = true;
    int ret = 1;
    while (true) {
        while (ret == 1) {
            std::cout << "Enter a character combination: \n";
            std::vector<std::string> input;
            std::string s;
            for (int i = 0; i < INPUT_SIZE; i++) {
                std::cin >> s;
                input.push_back(s);
            }
            std::vector<int> vec;
            ret = translate_input(vec, input);
            if (ret == 1) std::cout << "One or more characters invalid!\n";
            else {
               universe = wordle_graph.search_match(true, vec, universe, is_first);
            }
        }
        ret = 1;
        is_first = false;

        int j = 0;
        for (int i = 0; i < universe.size(); i++) {
            j++;
        }
        std::cout << j << " words in the universe\n";

    }

    return 0;
}