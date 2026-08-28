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

    void bfsHelper(int src, vector<bool> &visited) {
        queue<int>q;

        q.push(src);
        visited[src] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();

            cout<<u<<" ";
            for(int v: l[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    void bfs() {
        vector<bool>visited(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                bfsHelper(i, visited);
            }
        }
        cout<<endl;
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
        vector<int>visited(V, false);

        for(int i=0; i<V; i++) {
            if(!visited[i]) {
                dfsHelper(i, visited);
            }
        }
        cout<<endl;
    }
};

int main() {

    Graph g(10);

    g.addEdge(0, 1);
    g.addEdge(1, 3);
    g.addEdge(0, 2);
    g.addEdge(4, 5);
    g.addEdge(6, 9);
    g.addEdge(7, 8);

    cout<<"BFS: ";
    g.bfs();

    cout<<"DFS: ";
    g.dfs();
    return 0;
}