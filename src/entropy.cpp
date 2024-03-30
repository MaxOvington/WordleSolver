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
#include <thread>
#include <mutex>

#define DEFAULT 0
#define GREEN 1
#define ORANGE 2
#define RED 3
#define ALPH_OFFSET 121
#define NUM_STEPS 243

bool letter_is_present(char c, std::vector<int> input) {
    for (int i = 0; i < input.size(); i++) {
        if (input[i] < NUM_LETTERS && 
        (input[i] - ((26 * i) + 1) == (c - 'a') || input[i] == (c - 'a'))) {
            return true;
        }
    }
    return false;
}

void print_loading_bar(bool &calc, int &cnt, int total, std::mutex &mtx) {
    double crr = 0.0;
    std::string bar (20, ' ');
    double curr_percentage = 0.05;
    int j = 0;
    mtx.lock();
    while (!calc) {
    mtx.unlock();
        system("clear");
        crr = (cnt * 1.0)/total;
        std::cout << "[" << bar << "] " << (crr * 100.0) << "%" << std::endl;
        if (crr >= curr_percentage) {
            bar[j] = '#';
            j++;
            curr_percentage += 0.05;
        }
    }
    mtx.unlock();
}

std::vector<std::pair<double,std::pair<double, int>>> generate_entropy(int total, std::vector<int> &universe, Graph &g) {

    auto ret = std::vector<std::pair<double,std::pair<double, int>>>(universe.size());

    int cnt = 0;
    bool calculated = false;

    std::mutex mtx;
    std::thread loading_bar(print_loading_bar, std::ref(calculated), 
    std::ref(cnt), universe.size(), std::ref(mtx));

    int j = 0;
    #pragma omp parallel for
    for (int i = 0; i < universe.size(); i++) {
        double e = do_entropy2(total, universe[i], universe, g);
        ret[i] = std::make_pair(g.wordlist_[universe[i]].second, std::make_pair(e, universe[i]));
        cnt++;
    }
    mtx.lock();
    calculated = true;
    mtx.unlock();

    loading_bar.join();
    system("clear");

    return ret;
}

double entropy(int total, int word, std::vector<int> universe, Graph &g) {
    auto input = std::vector<int>();
    double p = do_entropy(total, input, word, universe, g, 0, DEFAULT);
    return p;
}

int generate_word_match(std::string &curr, std::string &target) {
    //get target word
    auto alph = std::vector<int>(26, 0);
    for (int i = 0; i < target.size(); i++) {
        alph[target[i] - 'a']++;
    }

    auto curr_alph = std::vector<int>(26, 0);
    int num = 0;
    for (int i = 0; i < curr.size(); i++) {
        if (curr[i] == target[i]) {
            num = (num * 3) + 1;
        } else if (curr[i] != target[i] &&
        curr_alph[curr[i] - 'a'] < alph[curr[i] - 'a'] ) {
            num = (num * 3) + 2;
        } else if (curr[i] != target[i] && 
        curr_alph[curr[i] - 'a'] >= alph[curr[i] - 'a']) {
            num = (num * 3) + 3;
        }
        curr_alph[curr[i] - 'a']++;
    }
    return num - ALPH_OFFSET;
}

double do_entropy2(int total, int word, std::vector<int> universe, Graph &g) {
    auto entropy_list = std::vector<int>(NUM_STEPS, 0);

    double entropy = 0.0;
    int k = 0;
    for (int i = 0; i < universe.size(); i++) {
        int pos = generate_word_match(g.wordlist_[word].first, g.wordlist_[universe[i]].first);
        entropy_list[pos]++;
        k++;
    }
    for (int i = 0; i < entropy_list.size(); i++) {
        double p = (entropy_list[i] * 1.0) / total;
        if (p == 0.0) entropy += 0.0;
        else entropy += p * log2(1.0/p);
    }
    return entropy;

}

double do_entropy(int total, std::vector<int> input, int word, std::vector<int> universe, Graph &g, int index, int type) {

    //TODO make wordlist not public!!
    if (index >= 5) {
        universe = g.search_match(input, universe, false);
        double p = (1.0 * universe.size()) / total;
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
    char c = g.wordlist_[word].first[index];

    if (type == GREEN) {
        input.push_back(c - 'a' + (26 * (index + 1)));
    } else if (type == ORANGE) {
        input.push_back(c - 'a');
        input.push_back(c - 'a' + (26 * (index + 1)) + NUM_LETTERS);
    } if (type == RED) {
        if (!letter_is_present(c, input)) {
            input.push_back(c - 'a' + NUM_LETTERS);
        } else {
            return 0.0;
        }
    }
    index++;
    return do_entropy(total, input, word, universe, g, index++, DEFAULT);
}