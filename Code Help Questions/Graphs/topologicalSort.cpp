#include <bits/stdc++.h>
using namespace std;

class DFS {
  public:
    void topoSort(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &s) {
        visited[node] = true;

        for(auto i:adj[node]) {
            if(!visited[i]) {
                topoSort(i, adj, visited, s);
            }
        }

        s.push(node);
    }
    
    vector<int> sortInit(vector<vector<int>> adj, int v) {
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
};

// Using BFS
class KahnsAlgorithm {
  public:
    
    vector<int> topoSort(vector<vector<int>> adj, int v) {
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
        return ans;
    }
};

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here
    vector<vector<int>> adj(v);
    for(int i=0; i<e; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        
        adj[u].push_back(v);
    }
    
//     DFS obj;
//     return obj.sortInit(adj, v);
    
    KahnsAlgorithm obj;
    return obj.topoSort(adj, v);
}