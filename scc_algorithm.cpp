//
// Created by ASUS on 15.11.2018.
//
#include <vector>
#include <stack>
#include <iostream>
#include <set>
#include "graph.h"

using namespace std;
class scc_algorithm{
public:
    const int UNVISITED = -1;
    int N;
    vector<set<int> > *adj;
    int id = 0;
    int scc_count = 0;

    vector<int> ids;
    vector<int> low;
    vector<bool> in_stack;
    vector<int> which_scc;
    stack<int> st;
    vector<set<int> > scc_set;

    scc_algorithm(const graph& gr){
        N = gr.V;
        adj = gr.adj;
        for (int i = 0; i < N; ++i) {
            ids.push_back(UNVISITED);
            low.push_back(0);
            in_stack.push_back(false);
            which_scc.push_back(0);
        }
    }
    vector<set<int> >* find_scc(){
        for (int i = 0; i < N; ++i) {
            if(ids[i] == UNVISITED)
                dfs(i);
        }
        return &scc_set;
    }
    void dfs(int at){
        st.push(at);
        in_stack[at] = true;
        ids[at] = low[at] = id++;
        //cout << at << endl;
        for(int to: (*adj)[at]){
            if(ids[to] == UNVISITED)
                dfs(to);
            if(in_stack[to])
                low[at] = min(low[at], low[to]);
        }

        if(ids[at] == low[at]){
            //cout << at << " true" << endl;
            set<int> at_set;
            scc_set.push_back(at_set);
            int m = scc_set.size()- 1;

            while(!st.empty()){
                int k = st.top();
                in_stack[k] = false;
                low[k] = ids[at];
                //cout << k << " stack" << endl;
                st.pop();
                which_scc[k] = m;
                scc_set[m].insert(k);
                if(k == at)
                    break;
            }
            scc_count++;
        }
    }

};

