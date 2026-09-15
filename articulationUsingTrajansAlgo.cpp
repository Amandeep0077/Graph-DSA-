#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>>adj;
    int V;
    int time = 0;
    vector<int>dt, low;
    
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int u, int parU, set<int> &criticalPoints) {
        dt[u] = low[u] = ++time;
        int children = 0;

        for(int i=0; i<adj[u].size(); i++) {
            int v = adj[u][i];

            if(dt[v] == -1) {
                children++;
                dfs(v, u, criticalPoints);
                //update low
                low[u] = min(low[u], low[v]);

                if(parU != -1 &&  low[v] >= dt[u]) {
                    //Articulation point => Critical point
                    criticalPoints.insert(u);
                }

            }
            else if(v != parU) {
                low[u] = min(low[u], dt[u]);
            }
        }

        if(parU == -1 && children > 1) {
            //Articulation point => Critical point
            criticalPoints.insert(u);
        }
    }

    int articulationPoint() {
        time = 0;
        dt.resize(V, -1);
        low.resize(V);

        set<int>criticalPoints;

        for(int i=0; i<V; i++) {
            if(dt[i] == -1) {
                dfs(i, -1, criticalPoints);
            }
        }

        return criticalPoints.size();
    }
};


int main() {

    Graph graph(6);

    graph.addEdge(1, 0);
    graph.addEdge(1, 2);
    graph.addEdge(1, 4);
    graph.addEdge(4, 5);
    graph.addEdge(3, 4);

    cout<<"Total number of Critical Points: "<<graph.articulationPoint();


    return 0;
}