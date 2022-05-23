#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;

class Solution {
    public:

    void createMap(int in[], map<int, int> &nodeToIndex, int n) {
        for(int i=0; i<n; i++)
            nodeToIndex[in[i]] = i;
    }
        
    Node *solve(int in[], int post[], int &index, int inStart, int inEnd, int n, map<int, int> &nodeToIndex) {
        
        if(index < 0 || inStart > inEnd)
            return NULL;
            
        int element = post[index--];
        Node *root = new Node(element);
        int pos = nodeToIndex[element];
        
        root->right = solve(in, post, index, pos+1, inEnd, n, nodeToIndex);
        root->left = solve(in, post, index, inStart, pos-1, n, nodeToIndex);
        
        return root;
        
    }

    Node *buildTree(int in[], int post[], int n) {
        // Your code here
        map<int, int> nodeToIndex;
        createMap(in, nodeToIndex, n);
        
        int postStart = n-1;
        Node *ans = solve(in, post, postStart, 0, n-1, n, nodeToIndex);
        return ans;
    }
};