#include <bits/stdc++.h>
using namespace std;

void dfs(int node, int parent, unordered_map<int, list<int>> &adj, unordered_map<int, bool> &vis,
    vector<int> &disc, vector<int> &low, int &timer, vector<int> &ap) {

        vis[node] = true;
        disc[node] = low[node] = timer++;
        int child = 0;

        for(auto nbr:adj[node]) {
            if(nbr == parent)
                continue;
            else if(!vis[nbr]) {
                dfs(nbr, node, adj, vis, disc, low, timer, ap);
                low[node] = min(low[node], low[nbr]);

                if(low[nbr] >= disc[node] && parent != -1)
                    ap.push_back(node);
            } else {
                // Backedge
                low[node] = min(low[node], disc[nbr]);
            }
            child++;
        }

        if(parent == -1 && child > 1) {
            ap.push_back(node);
        }
    }

int main() {
    int n = 5;
    vector<pair<int,int>> edges;
    edges.push_back({0,1});
    edges.push_back({0,3});
    edges.push_back({0,4});
    edges.push_back({2,1});
    edges.push_back({3,4});

    unordered_map<int, list<int>> adj;
    for(int i=0; i<n; i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int timer = 0, parent = -1;
    vector<int> disc(n, -1), low(n, -1), ap;
    unordered_map<int, bool> vis;

    for(int i=0; i<n; i++) {
        if(!vis[i]) {
            dfs(i, parent, adj, vis, disc, low, timer, ap);
        }
    }

    cout << "\nArticulations points: ";
    for(auto i:ap)
        cout << i << ", ";
    cout << endl;
}