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
    
    bool disCycleBFS(int src, vector<bool> &visited) {
        queue<pair<int, int>>q;

        q.push({src, -1});
        visited[src] = true;

        while(!q.empty()) {
            int u = q.front().first;
            int parU = q.front().second;
            q.pop();

            for(int v: l[u]) {
                if(!visited[v]) {
                    q.push({v, u});
                    visited[v] = true;
                }
                else if(v != parU){
                    return true;
                }
            }

            
        }

        return false;
    }

    bool isCycle() {
        vector<bool>visited(V, false);

        return disCycleBFS(0, visited);
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(0, 3);
    g.addEdge(3, 4);

    cout<< g.isCycle();
    
    return 0;
}