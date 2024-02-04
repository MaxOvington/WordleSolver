#include <iostream>
#include "graph/graph.h"
#include "graph/process.h"
#include <filesystem>
#include <fstream>

int main (void) {
    int num_words = 0;
    std::filesystem::path p = std::filesystem::current_path();
    p = (p.parent_path().parent_path()) / "src/words.txt";

    std::cout << "Current path is " << p << "\n";

    std::ifstream fp(p); 
    std::string lne;
    while (getline(fp, lne)) {
        if (!lne.empty()) num_words++;
    }

    Graph wordle_graph(num_words);
    
    //read from file
    //wordle_graph.print_graph_list();
    
    wordle_graph.print_words();

    int ret = 1;
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
    }

    std::cout << "Success!\n";

    return 0;
}