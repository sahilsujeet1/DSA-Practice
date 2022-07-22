#include <bits/stdc++.h>
using namespace std;

void dfs(int node, unordered_map<int, list<int>> &adj, stack<int> &st, unordered_map<int, bool> &vis) {
    vis[node] = true;
    
    for(auto i:adj[node]) {
        if(!vis[i]) {
            dfs(i, adj, st, vis);
        }
    }
    
    st.push(node);
}

void revDfs(int node, unordered_map<int, list<int>> &trans, unordered_map<int, bool> &vis) {
    vis[node] = true;
    
    for(auto i:trans[node]) {
        if(!vis[i]) {
            revDfs(i, trans, vis);
        }
    }
}

int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
	// Write your code here.
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    
    unordered_map<int, bool> vis(v);
    stack<int> st;
    
    for(int i=0; i<v; i++) {
        if(!vis[i]) {
            dfs(i, adj, st, vis);
        }
    }
    
    
    unordered_map<int, list<int>> trans;
    for(int i=0; i<v; i++) {
        vis[i] = false;
        for(auto u:adj[i]) {
            trans[u].push_back(i);
        }
    }
    
    int count = 0;
    while(!st.empty()) {
        int top = st.top();
        st.pop();
        
        if(!vis[top]) {
            count++;
            revDfs(top, trans, vis);
        }
    }
    
    return count;
}