#include <bits/stdc++.h>
using namespace std;

void topoSort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s) {
    visited[node] = true;
    
    for(auto i:adj[node]) {
        if(!visited[i]) {
            topoSort(i, adj, visited, s);
        }
    }
    
    s.push(node);
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
    vector<int> ans;
    vector<bool> visited(v);
    stack<int> s;
    
    for(int i=0; i<v; i++) {
        if(!visited[i]) {
            topoSort(i, adj, visited, s);
        }
    }
    
    while(!s.empty()) {
        ans.push_back(s.top());
        s.pop();
    }
    
    return ans;
}