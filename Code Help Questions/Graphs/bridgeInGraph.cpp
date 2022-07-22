#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, int &timer, unordered_map<int, list<int>> &adj,
        unordered_map<int, bool> &vis, vector<int> &disc, vector<int> &low,     vector<vector<int>> &result) {
    
    vis[node] = true;
    disc[node] = low[node] = timer++;
    
    for(auto i:adj[node]) {
        if(i == parent)
            continue;
        else if(!vis[i]) {
            dfs(i, node, timer, adj, vis, disc, low, result);
            low[node] = min(low[node], low[i]);
            
            if(low[i] > disc[node]) {
                vector<int> edges = {i, node};
                result.push_back(edges);
            }
        } else {
            // Backedge
            low[node] = min(low[node], disc[i]);
        }
    }
}

vector<vector<int>> findBridges(vector<vector<int>> &edges, int v, int e) {
    // Write your code here
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int timer = 0;
    int parent = -1;
    vector<int> disc(v);
    vector<int> low(v);
    unordered_map<int, bool> vis;
    
    for(int i=0; i<v; i++) {
        low[i] = -1;
        disc[i] = -1;
    }
    
    vector<vector<int>> result;
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, parent, timer, adj, vis, disc, low, result);
        }
    }
    
    return result;
}