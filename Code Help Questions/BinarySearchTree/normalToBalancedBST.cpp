#include<bits/stdc++.h>
#include "node.cpp"

void inorder(Node* root, vector<int> &in) {
    if(root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* BSTtoBalanced(int s, int e, vector<int> &in) {
    if(s > e)
        return NULL;
    
    int mid = (s+e)/2;
    Node* root = new Node(in[mid]);
    root->left = BSTtoBalanced(s, mid-1, in);
    root->right = BSTtoBalanced(mid+1, e, in);
    
    return root;
}

Node* balancedBst(Node* root) {
    // Write your code here.
    vector<int> in;
    inorder(root, in);
    return BSTtoBalanced(0, in.size()-1, in);
}
