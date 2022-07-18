#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Creating adjacency list for graph
    unordered_map<int, list<pair<int, int> > > adj;
    for(int i=0; i<edges; i++) {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }
    
    // Creating distance vector and set
    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int> > st;
    // Set source distance to 0
    dist[source] = 0;
    st.insert(make_pair(0, source));
    
    while(!st.empty()) {
        auto top = *(st.begin());
        int topNode = top.second;
        int topDist = top.first;
        
        st.erase(top);
        
        for(auto i:adj[topNode]) {
            if(topDist + i.second < dist[i.first]) {
                auto record = st.find(make_pair(dist[i.first], i.first));
                if(record != st.end()) {
                    st.erase(record);
                }
                
                dist[i.first] = topDist + i.second;
                
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    
    return dist;
}
