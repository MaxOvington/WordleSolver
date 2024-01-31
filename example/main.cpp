#include <iostream>
#include "graph/graph.h"

int main (void) {
    int x;

    Graph wordle_graph(18);
    std::cout << "The value of the class is " << wordle_graph.get_val() << "\n";
    std::cout << "Now try enter a number: ";
    std::cin >> x;
    wordle_graph.set_val(x);
    std::cout << "The value of the class now is " << wordle_graph.get_val() << "\n";
    return 0;
}