#include<bits/stdc++.h>
using namespace std;

class Graph {
public:
    vector<vector<int>>adj;
    int V;
    
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
    }

    void topSort(int curr, vector<bool> &vis, stack<int> &s) {
        vis[curr] = true;

        for(int neigh: adj[curr]) {
            if(!vis[neigh]) {
                topSort(neigh, vis, s);
            }
        }

        s.push(curr);
    }

    void dfs(int curr, vector<bool> &vis, vector<vector<int>> &transpose) {
        vis[curr] = true;

        cout<<curr<<"   ";

        for(int neigh: transpose[curr]) {
            if(!vis[neigh]) {
                dfs(neigh, vis, transpose);
            }
        }
    }

    void kosaraju() {  //TC : O(V+E)
        //step1 : topologiacl sorting
        stack<int>s;
        vector<bool>vis(V, false);

        //TC : O(V+E)
        for(int i=0; i<V; i++) {
            if(!vis[i]) {
                topSort(i, vis, s);
            }
        }

        // step 2 : Transpose Grph

        vector<vector<int>>transpose(V);

        //TC : O(V+E)
        for(int u=0; u<V; u++) { // u---->v
            vis[u] = false;
            for(int v: adj[u]) {  //v---->u
                transpose[v].push_back(u);
            }
        }

        cout<<"Printing SCC: \n";
        // step 3 : dfs on transpose graph


        while(s.size()>0) {  //TC : O(V+E)
            int curr = s.top();
            s.pop();

            if(!vis[curr]) {
                dfs(curr, vis, transpose);
                cout<<endl;
            }
        }
    }
   
};


int main() {

    Graph graph(5);

    graph.addEdge(0, 2);
    graph.addEdge(0, 3);
    graph.addEdge(1, 0);
    graph.addEdge(2, 1);
    graph.addEdge(3, 4);

    graph.kosaraju();


    return 0;
}