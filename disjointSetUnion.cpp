#include<bits/stdc++.h>
using namespace std;

class DisjointSetUnion {
public:
    int n;
    vector<int>parent, rank;

    DisjointSetUnion(int n) {
        this->n = n;

        parent.resize(n);
        rank.resize(n, 0);

        for(int i=0; i<n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }

    void unionByRank(int a, int b) {
        int parA = find(a);
        int parB = find(b);

        if(parA == parB) return;

        if(rank[parA] == rank[parB]) {  //CASE 1
            parent[parB] = parA;
            rank[parA]++;
        }
        else if(rank[parA] > rank[parB]) {   //CASE 2
            parent[parB] = parA;
        }
        else {                                //CASE 3
            parent[parA] = parB;
        }
    }


    int find(int x) {
        if(parent[x] == x) {
            return x;
        }

        return parent[x] = (parent[x]); //path compression
    }

    void getInfo() {
        for(int i=0; i<n; i++) {
            cout<<parent[i]<<"  ";
        }
        cout<<endl;


        for(int i=0; i<n; i++) {
            cout<<rank[i]<<"  ";
        }
    }
};

int main() {
    
    DisjointSetUnion dsu(6);

    dsu.unionByRank(0, 2);
    cout<< dsu.find(2)<< endl;

    dsu.unionByRank(1, 3);
    dsu.unionByRank(2, 5);
    dsu.unionByRank(0, 3);

    cout<< dsu.find(2)<< endl;

    dsu.unionByRank(0, 4);

    dsu.getInfo();

    return 0;
}