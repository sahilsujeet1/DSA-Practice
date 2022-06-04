#include<bits/stdc++.h>
#include "node.cpp"

Node* solve(int mini, int maxi, vector<int> &preorder, int &i) {
    if(i >= preorder.size())
        return NULL;
    if(preorder[i] < mini || preorder[i] > maxi)
        return NULL;
    
    Node* root = new Node(preorder[i++]);
    root->left = solve(mini, root->data, preorder, i);
    root->right = solve(root->data, maxi, preorder, i);
    
    return root;
}

Node* preorderToBST(vector<int> &preorder) {
    // Write your code here.
    int i = 0;
    return solve(INT_MIN, INT_MAX, preorder, i);
}