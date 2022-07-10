#include<bits/stdc++.h>
using namespace std;

bool dfs(int node, unordered_map<int, list<int>> &adj, 
         unordered_map<int, bool> &visited, unordered_map<int, bool> &dfsVisited) {
    visited[node] = true;
    dfsVisited[node] = true;
    
    for(auto i:adj[node]) {
        if(!visited[i]) {
            bool isFound = dfs(i,adj, visited, dfsVisited);
            if(isFound)
                return true;
        } else if(dfsVisited[i]) {
            return true;
        }
    }
    dfsVisited[node] = false;
    return false;
}

bool cycleBFSKahnsAlgo(unordered_map<int, list<int>> adj, int v) {
        queue<int> q;
        vector<int> indegree(v);
        vector<int> ans;
        
        for(int i=0; i<v; i++) {
            for(auto j:adj[i]) {
                indegree[j]++;
            }
        }
        
        for(int i=0; i<v; i++) {
            if(indegree[i] == 0)
                q.push(i);
        }
        
        while(!q.empty()) {
            int front = q.front();
            q.pop();
            ans.push_back(front);
            
            for(auto i:adj[front]) {
                indegree[i]--;
                if(indegree[i] == 0) {
                    q.push(i);
                }
            }
        }
        return ans.size() != adj.size();
    }

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
    unordered_map<int, list<int>> adj;
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        
        adj[u].push_back(v);
    }
    
    unordered_map<int, bool> visited, dfsVisited;
    
    for(int i=1; i<=n; i++) {
        if(!visited[i]) {
            bool cyclePresent = dfs(i, adj, visited, dfsVisited);
            if(cyclePresent)
                return true;
        }
    }
    return false;
}