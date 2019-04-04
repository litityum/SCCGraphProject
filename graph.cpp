//
// Created by ASUS on 15.11.2018.
//
#include <vector>
#include <iostream>
#include "graph.h"

using namespace std;

graph::graph(int v) {
    this->V = v;
    this->adj = new vector<set<int> >(v);
}
void graph::add_edge(int i, int j) {
    (*adj)[i].insert(j);
}
graph::~graph() {
    delete adj;
}


