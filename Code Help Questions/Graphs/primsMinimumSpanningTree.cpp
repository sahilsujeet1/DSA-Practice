#include <bits/stdc++.h>
using namespace std;

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<g.size(); i++) {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int w = g[i].second;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    
    vector<int> key(n+1, INT_MAX);
    vector<int> parent(n+1, -1);
    vector<bool> mst(n+1, false);
    
    parent[1] = -1;
    key[1] = 0;
    
    for(int i=1; i<=n; i++) {
        int mini = INT_MAX;
        int u;
        
        for(int v=1; v<=n; v++) {
            if(!mst[v] && key[v] < mini) {
                u = v;
                mini = key[v];
            }
        }
        
        mst[u] = true;
        
        for(auto it:adj[u]) {
            int v = it.first;
            int w = it.second;
            
            if(!mst[v] && w < key[v]) {
                parent[v] = u;
                key[v] = w;
            }
        }
    }
    
    vector<pair<pair<int, int>, int>> result;
    
    for(int i=2; i<=n; i++) {
        result.push_back({{parent[i], i}, key[i]});
    }
    
    return result;
}
