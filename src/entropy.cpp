#include <iostream>
#include "graph/process.h"
#include "graph/graph.h"
#include "graph/entropy.h"
#include <string>
#include <fstream>
#include <cmath>
#include <unistd.h> 
#include <stdlib.h> 
#include <omp.h>

#define DEFAULT 0
#define GREEN 1
#define ORANGE 2
#define RED 3

bool letter_is_present(char c, std::vector<int> input) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < NUM_LETTERS && 
        (input[i] - ((26 * i) + 1) == (c - 'a') || input[i] == (c - 'a'))) {
            return true;
        }
    }
    return false;
}


std::vector<std::pair<int, double>> generate_entropy(int total, std::vector<int> &universe, Graph &g) {

    auto ret = std::vector<std::pair<int, double>>(universe.size());

    std::string bar (20, ' ');

    omp_set_num_threads(4);

    // int x = 2;
    // #pragma omp parallel for reduction(+: x)
    // for (int i = 0; i < 10000; i++) {
    //     std::cout << omp_get_thread_num() << "\n";
    //     sleep(1);
    //     x += i;
    // }

    int cnt = 0;
    double curr_percentage = 0.05;
    int j = 0;
    #pragma omp parallel for
    for (int i = 0; i < 100; i++) {
        double e = entropy(total, universe[i], universe, g);
        ret[i] = std::make_pair(universe[i], e);
        cnt++;
        system("clear");
        double crr = (cnt * 1.0)/100;
        std::cout << "[" << bar << "] " << (crr * 100.0) << "%" << std::endl;
        if (crr >= curr_percentage) {
            bar[j] = '#';
            j++;
            curr_percentage += 0.05;
        }
    }
    std::cout << "\n";
    return ret;
}

double entropy(int total, int word, std::vector<int> universe, Graph &g) {
    //std::cout << "finding word.." << g.wordlist_[word] << "\n";
    auto input = std::vector<int>();
    double p = do_entropy(total, input, word, universe, g, 0, DEFAULT);
    //std::cout << "Total entropy is " << p << "\n";
    return p;
}

double do_entropy(int total, std::vector<int> input, int word, std::vector<int> universe, Graph &g, int index, int type) {

    //TODO make wordlist not public!!

    if (index >= 5) {
        // for (int i = 0; i < input.size(); i++) {
        //     std::cout << input[i] << " ";
        // }
        // std::cout << "\n";
        universe = g.search_match(false, input, universe, false);
        //std::cout << "value is " << (1.0 * universe.size()) / total << "\n";
        double p = (1.0 * universe.size()) / total;
        //std::cout << "next value is " << p << ", " << log2(1.0/p) << "\n";
        if (p == 0.0) return 0.0;
        double x = p * log2(1.0/p);
        return x;
    }

    if (type == DEFAULT) {
        return do_entropy(total, input, word, universe, g, index, GREEN) +
        do_entropy(total, input, word, universe, g, index, ORANGE) + 
        do_entropy(total, input, word, universe, g, index, RED);
    } 
    
    //get word index
    char c = g.wordlist_[word][index];
    
    if (type == GREEN) {
        //std::cout << "Green.. " << index <<  "\n";
        input.push_back(c - 'a' + (26 * (index + 1)));

    } else if (type == ORANGE) {
        //std::cout << "Orange.. " << index <<  "\n";
        input.push_back(c - 'a');
        input.push_back(c - 'a' + (26 * (index + 1)) + NUM_LETTERS);

    } if (type == RED) {
        //std::cout << "Red.. " << index <<  "\n";
        if (!letter_is_present(c, input)) {
            //std::cout << "letter not present\n";
            input.push_back(c - 'a' + NUM_LETTERS);
        } else {
            return 0.0;
        }
    }
    //std::cout << "Recursing now... \n";
    index++;
    //sleep(2);
    return do_entropy(total, input, word, universe, g, index++, DEFAULT);
}