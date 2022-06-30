#include <bits/stdc++.h>
using namespace std;

class Graph {
    public:
    unordered_map<int, list<pair<int, int> > > adj;
    stack<int> s;


    void addEdge(int u, int v, int w) {
        pair<int, int> p = make_pair(v, w);
        adj[u].push_back(p);
    }

    void printAdj() {
        for(auto i: adj) {
            cout << i.first << " -> ";
            for(auto j: i.second) {
                cout << j.first << ", ";
            } cout << endl;
        } cout << endl;
    }
    

    void topologicalSort(int node, unordered_map<int, bool> &visited) {
        visited[node] = true;

        for(auto i:adj[node]) {
            if(!visited[i.first]) {
                visited[i.first] = true;
                topologicalSort(i.first, visited);
            }
        }

        s.push(node);
    }

    void getShortestPath(vector<int> &dist, int src) {
        dist[src] = 0;

        vector<int> topo;
        while(!s.empty()) {
            int top = s.top();
            s.pop();

            if(dist[top] != INT_MAX) {
                for(auto i: adj[top]) {
                    if(dist[top] + i.second < dist[i.first]) {
                        dist[i.first] = dist[top] + i.second;
                    }
                }
            }
        }


    }

};

int main() {
    Graph g;
    g.addEdge(0, 2, 2);
    g.addEdge(0, 5, -3);
    g.addEdge(2, 6, 1);
    g.addEdge(6, 1, 6);
    g.addEdge(5, 4, 4);
    g.addEdge(3, 0, -2);
    g.addEdge(3, 4, 5);

    int n = 7;
    int src = 0;

    g.printAdj();
    unordered_map<int, bool> visited;
    vector<int> distance(n, INT_MAX);

    for(int i=0; i<n; i++) {
        if(!visited[i])
            g.topologicalSort(i, visited);
    }

    g.getShortestPath(distance, src);

    for(auto i:distance) {
        cout << i << ", ";
    } cout << endl;
}