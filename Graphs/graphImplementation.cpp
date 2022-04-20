#include<bits/stdc++.h>
using namespace std;
void addEdgeList(vector<int> adj[], int u, int v) {
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void addEdgeMatrix(vector<vector<int>> &mat, int u, int v) {
    mat[u][v] = 1;
    mat[v][u] = 1;
}

void printMatrix(vector<vector<int>> &mat) {
    cout << "\nAdjacency Matrix Graph Representation" << endl << endl;

    cout << "    ";
    for(int i=0; i<mat.size(); i++) 
        cout << i << " ";
    cout << "\n    ";
    for(int i=0; i<mat.size(); i++) 
        cout << "-" << " ";
    cout << endl;

    for(int i=0; i<mat.size(); i++) {
        cout << i << " | ";
        for(int j=0; j<mat[i].size(); j++) {
            cout << mat[i][j] << " ";
        } cout << endl;
    }
}
void printList(vector<int> adj[], int n) {
    cout << endl << endl << "Adjacency List Graph Representation" << endl;

    for(int i=0; i<n; i++) {
        cout << i << " : ";
        for(auto e:adj[i]) {
            cout << e << " ";
        } cout << endl;
    }
}

int main() {
    int n = 5;
    vector<int> adj[n];
    /*
          1   
         / \
        0   2--3
        | /   /
        4-----
    */
    addEdgeList(adj, 0,1);
    addEdgeList(adj, 0,4);
    addEdgeList(adj, 1,2);
    addEdgeList(adj, 2,3);
    addEdgeList(adj, 2,4);
    addEdgeList(adj, 3,4);
    
    printList(adj, n);

    vector<vector<int>> matrix;
    for(int i=0; i<n; i++) {
        vector<int> row;
        for(int j=0; j<n; j++) {
            row.push_back(0);
        }
        matrix.push_back(row);
    }

    addEdgeMatrix(matrix, 0,1);
    addEdgeMatrix(matrix, 0,4);
    addEdgeMatrix(matrix, 1,2);
    addEdgeMatrix(matrix, 2,3);
    addEdgeMatrix(matrix, 2,4);
    addEdgeMatrix(matrix, 3,4);

    printMatrix(matrix);
}