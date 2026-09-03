#include<bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    list<int> *l; //int *array

public:
    Graph(int V) {
        this->V = V;
        l = new list<int> [V]; //arr = new int [V];
    }

    void addEdge(int u, int v) {
        l[u].push_back(v); //only for directed graph
    }
    
    void dfs(int curr, vector<bool> &visited, stack<int> &s) {
        visited[curr] = true;

        for(int v: l[curr]) {
            if(!visited[v]) {
                dfs(v, visited, s);
            }
        }

        s.push(curr);
    }

    void topologicalSorting() {
        vector<bool>visited(V, false);
        stack<int>s;

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfs(i, visited, s);
            }
        }

        while(!s.empty()) {
            cout<<s.top()<<"  ";
            s.pop();
        }
    }
    
};

int main() {

    Graph g(6);

    g.addEdge(5, 0);
    g.addEdge(4, 0);
    g.addEdge(4, 1);
    g.addEdge(3, 1);
    g.addEdge(2, 3);
    g.addEdge(5, 2);

    g.topologicalSorting();
    
    return 0;
}