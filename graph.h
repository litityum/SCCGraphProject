//
// Created by ASUS on 15.11.2018.
//

#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include <set>

using namespace std;
class graph {
public:
    int V;
    vector<set<int> > *adj;

    graph(int v);
    void add_edge(int i, int j);
    ~graph();
};


#endif //GRAPH_H
