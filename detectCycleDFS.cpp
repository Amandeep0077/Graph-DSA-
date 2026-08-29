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
    
    bool disCycleDFS(int src, vector<bool> &visited, int parent) {
        visited[src] = true;


        for(int v: l[src]) {
            if(!visited[v]) {
                if(disCycleDFS(v, visited, src)) return true;
            }
            else if(parent != v) {
                return true;
            }
        }

        return false;
    }

    bool isCycle() {
        vector<bool>visited(V, false);

        return disCycleDFS(0, visited, -1);
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    // g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout<< g.isCycle();
    
    return 0;
}