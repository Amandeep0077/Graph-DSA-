#include<bits/stdc++.h>
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
        l[u].push_back(v);
        l[v].push_back(u);
    }

    void dfsHelper(int u, vector<int> &visited) {
        cout<<u<<" ";
        visited[u] = true;

        for(int v: l[u]) {
            if(!visited[v]) {
                dfsHelper(v, visited);
            }
        }
    }

    void dfs() {
        int src = 0;
        vector<int>visited(V, false);

        dfsHelper(src, visited);
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    g.dfs();
    return 0;
}