#include <iostream>
#include "graph/graph.h"
#include "graph/process.h"
#include "graph/entropy.h"
#include <filesystem>
#include <algorithm>
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

    Graph wordle_graph(num_words);

    //generate entropy list
    auto universe = wordle_graph.get_active_wordlist();
    generate_universe(universe, wordle_graph);

    std::cout << wordle_graph.wordlist_[16890] << "\n";

    bool is_first = true;
    int ret = 1;
    while (universe.size() > 1) {
        std::cout << "Enter a character combination: \n";
        std::vector<std::string> input;
        std::string s;

        for (int i = 0; i < INPUT_SIZE; i++) {
            std::cin >> s;
            if (s == "0x0") continue;
            input.push_back(s);
        }

        std::vector<int> vec;
        ret = translate_input(vec, input);
        if (ret == 1) {
            std::cout << "One or more characters invalid!\n";
            continue; 
        }
        universe = wordle_graph.search_match(vec, universe, is_first);
        generate_universe(universe, wordle_graph);
        std::cout << universe.size() << " word(s) in the universe\n";
        is_first = false;
    }

    return 0;
}