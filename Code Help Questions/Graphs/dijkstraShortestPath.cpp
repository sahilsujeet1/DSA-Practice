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
    
    // Run loop until set is empty
    while(!st.empty()) {
        // Fetch top record from set
        auto top = *(st.begin());
        int topNode = top.second;
        int topDist = top.first;
        
        // Remove top record from the set
        st.erase(top);
        
        // Traverse all the neighbours of the top node
        for(auto i:adj[topNode]) {
            // Check if sum of top node distance and neighbour node dist is less than existing neighbour node distance
            if(topDist + i.second < dist[i.first]) {
                // Find and remove node from set if already exists
                auto record = st.find(make_pair(dist[i.first], i.first));
                if(record != st.end()) {
                    st.erase(record);
                }
                
                // Update the distance of neighbouring node
                dist[i.first] = topDist + i.second;
                // Insert the new neighbour pair of new distance and node value
                st.insert(make_pair(dist[i.first], i.first));
            }
        }
    }
    
    return dist;
}
