#include<bits/stdc++.h>
using namespace std;

void bfs(unordered_map<int, set<int>> &adj, unordered_map<int, bool> &visited,
         vector<int> &ans, int node) {
    queue<int> q;
    
    q.push(node);
    visited[node] = true;
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        ans.push_back(front);
        for(auto i:adj[front]) {
            if(!visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    // Write your code here
    unordered_map<int, set<int>> adj;
    unordered_map<int, bool> visited;
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].insert(v);
        adj[v].insert(u);
    }
    
    vector<int> ans;
    
    for(int i=0; i<vertex; i++) {
        if(!visited[i]) {
            bfs(adj, visited, ans, i);
        }
    }
    
    return ans;
}