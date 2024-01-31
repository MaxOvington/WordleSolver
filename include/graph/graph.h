#pragma once

class Graph {
    public: 
        Graph(int const val);
        auto get_val() -> int const&;
        auto set_val(int x) -> void;

    private:
        int val_;

};

//constructor defined outside of scope, scoped by classname
Graph::Graph(int const val) {
    val_ = val;
}

auto Graph::get_val() -> int const& {
    return val_;
}

auto Graph::set_val(int x) -> void {
    val_ = x;
}