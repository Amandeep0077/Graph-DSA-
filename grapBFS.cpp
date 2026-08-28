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

    void bfs() {
        vector<bool>visted(V, false);
        queue<int>q;

        q.push(0);
        visted[0] = true;

        while(q.size() > 0) {
            int u = q.front();
            q.pop();

            cout<<u<<" ";
            for(int v: l[u]) {
                if(!visted[v]) {
                    visted[v] = true;
                    q.push(v);
                }
            }
        }
        cout<<endl;
    }
};

int main() {

    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 3);
    g.addEdge(2, 4);

    g.bfs();
    return 0;
}