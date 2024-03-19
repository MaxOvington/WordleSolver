#include <iostream>
#include "graph/process.h"
#include "graph/entropy.h"
#include <string>
#include <fstream>
#include <algorithm>

int translate_input(std::vector<int> &ret, std::vector<std::string> s) {
    for (int i = 0; i < s.size(); i++) {
        /*if 1st character not + or -, 
        if 2nd character not letter, 
        2nd not between 0 and 5, and string size is not 3 in size*/
        if ((s[i][0] == '+' || s[i][0] == '-') &&
            (s[i][1] >= 'a' && s[i][1] <= 'z') &&
            (s[i][2] >= '0' && s[i][2] <= '5') && 
            s[i].size() == 3) {
                if (s[i][0] != '0') {
                    int val = (s[i][1] - 97) + (26 * ((s[i][2] - 49) + 1));
                    if (s[i][0] == '-') val += NUM_LETTERS;
                    ret.push_back(val);
                }
        } else {
            return 1;
        }
    }
    return 0;
}

void generate_universe(std::vector<int> &universe, Graph &g) {
    auto retval = generate_entropy(universe.size(), universe, g);

    std::sort(retval.begin(), retval.end(), std::greater<std::pair<double, int>>());
    int size = (universe.size() < 20) ? universe.size() : 20;
    for (int i = 0; i < size; i++) {
        std::cout << i + 1 << " " << g.wordlist_[retval[i].second] << " , " << retval[i].first << "\n";
    }
}
