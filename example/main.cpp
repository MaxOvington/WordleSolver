#include <iostream>
#include "graph/graph.h"
#include "graph/process.h"
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

    int ret = 1;
    int rounds = 0;
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
            else wordle_graph.search_match(vec, rounds);
        }
        ret = 1;
        rounds++;
    }

    return 0;
}