//
// Created by ASUS on 15.11.2018.
//
#include "graph.h"
#include "scc_algorithm.cpp"
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;
int main(int argc, char* argv[]) {
    // below reads the input file
    // in your next projects, you will implement that part as well
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }



    // here, perform the input operation. in other words,
    // read the file named <argv[1]>
    ifstream infile(argv[1]);
    int v;
    infile >> v;
    graph huso(v);
    for(int i = 0; i < v; i++){
        int k;
        infile >> k;

        for (int j = 0; j < k; j++) {
            int e;
            infile >> e;
            e--;
            (*huso.adj)[i].insert(e);
        }
    }
    infile.close();

    scc_algorithm hop(huso);
    vector<set<int> > *scc = hop.find_scc();
    int k = scc->size();

    graph simple(k);
    vector<int> to_find_roots(k);
    for (int i = 0; i < k; ++i) {
        for(int m: (*scc)[i]){
            for(int pr: (*huso.adj)[m]){
                int which = hop.which_scc[pr];
                if(which == i)
                    continue;
                simple.add_edge(i, which);
                to_find_roots[which]++;
            }

        }
    }
    int root = 0;
    vector<int> roots;
    for (int i = 0; i < k; ++i) {
        if(to_find_roots[i] == 0){
            int h = 0;
            for(int m: (*scc)[i]){
                h = m + 1;
                break;
            }
            roots.push_back(h);
        }
    }
    root = roots.size();
    ofstream output(argv[2]);
    output << root;
    for (int i = 0; i < root; ++i) {
        output << " " << roots[i];
    }
    output.close();
}