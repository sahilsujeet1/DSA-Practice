#include<bits/stdc++.h>
using namespace std;

void addEdgeList(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printList(vector<int> adj[], int n) {
    cout << "Adjacency List Graph Representation" << endl;

    for(int i=0; i<n; i++) {
        cout << i << " : ";
        for(auto e:adj[i]) {
            cout << e << " ";
        } cout << endl;
    }
}

int main() {
    int n = 5;
    vector<int> adj[n];
    /*
          1   
         / \
        0   2--3
        | /   /
        4-----
    */
    addEdgeList(adj, 0,1);
    addEdgeList(adj, 0,4);
    addEdgeList(adj, 1,2);
    addEdgeList(adj, 2,3);
    addEdgeList(adj, 2,4);
    addEdgeList(adj, 3,4);
    
    printList(adj, n);
}