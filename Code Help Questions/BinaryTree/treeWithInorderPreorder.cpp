#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;

class Solution{
    public:
    
    void createMap(int in[], map<int, int> &nodeToIndex, int n) {
        for(int i=0; i<n; i++)
            nodeToIndex[in[i]] = i;
    }
    
    Node *solve(int in[], int pre[], int &index, int inStart, int inEnd, int n, map<int, int> &nodeToIndex) {
        
        if(index >= n || inStart > inEnd)
            return NULL;
            
        int element = pre[index++];
        Node *root = new Node(element);
        int pos = nodeToIndex[element];
        
        root->left = solve(in, pre, index, inStart, pos-1, n, nodeToIndex);
        root->right = solve(in, pre, index, pos+1, inEnd, n, nodeToIndex);
        
        return root;
        
    }
    
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        map<int, int> nodeToIndex;
        createMap(in, nodeToIndex, n);
        
        int preStart = 0;
        Node *ans = solve(in, pre, preStart, 0, n-1, n, nodeToIndex);
        return ans;
    }
};