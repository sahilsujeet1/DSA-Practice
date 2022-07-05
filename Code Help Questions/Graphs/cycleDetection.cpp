#include<bits/stdc++.h>
using namespace std;

// Using BFS
bool isCyclicBFS(int node, unordered_map<int, list<int>> &adj, 
              unordered_map<int, bool> &visited) {
    unordered_map<int, int> parent;
    
    parent[node] = -1;
    visited[node] = true;
    queue<int> q;
    q.push(node);
    
    while(!q.empty()) {
        int front = q.front();
        q.pop();
        
        for(auto i:adj[front]) {
            if(visited[i] && parent[front] != i)
                return true;
            else if(!visited[i]) {
                visited[i] = true;
                q.push(i);
                parent[i] = front;
            }
        }
    }
    return false;
}

// Using DFS
bool isCyclicDFS(int node, int parent, unordered_map<int, list<int>> &adj, 
              unordered_map<int, bool> &visited) {
    visited[node] = true;
    
    for(auto i:adj[node]) {
        if(!visited[i]) {
            bool isDetected = isCyclicDFS(i, node, adj, visited);
            if(isDetected)
                return true;
        } else if(parent != i)
            return true;
    }
    return false;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    // Write your code here.
    unordered_map<int, list<int>> adj;
    unordered_map<int, bool> visited;
    
    for(int i=0; i<edges.size(); i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    for(int i=0; i<n; i++) {
        if(!visited[i]) {
//             bool ans = isCyclicBFS(i, adj, visited);
            bool ans = isCyclicDFS(i, -1, adj, visited);
            
            if(ans)
                return "Yes"; 
        }
    }
    return "No";
}
