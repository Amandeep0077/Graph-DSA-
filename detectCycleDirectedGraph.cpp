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
    
    bool isCycleDirDFS(int curr, vector<bool> &visited, vector<bool> &recPath) {
        visited[curr] = true;
        recPath[curr] = true;

        for(int v: l[curr]) {
            if(!visited[v]) {
                if(isCycleDirDFS(v, visited, recPath)) return true;
            }
            else if(recPath[v]) {
                return true;
            }
        }

        recPath[curr] = false;
        
        return false;
    }

    bool isCycle() {
        vector<bool>visited(V, false);
        vector<bool>recPath(V, false);

        return isCycleDirDFS(0, visited, recPath);
    }
};

int main() {

    Graph g(4);

    g.addEdge(0, 2);
    g.addEdge(3, 2);
    g.addEdge(3, 0);
    g.addEdge(1, 0);

    cout<< g.isCycle();
    
    return 0;
}