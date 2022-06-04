#include<bits/stdc++.h>
#include "node.cpp"

void inorder(Node* root, vector<int> &in) {
    if(root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

Node* flatten(Node* root)
{
    // Write your code here
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    
    Node* newRoot = new Node(in[0]);
    Node* curr = newRoot;
    
    for(int i=1; i<n; i++) {
        Node* temp = new Node(in[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = curr->right;
    }
    
    curr = new Node(in[n-1]);
    curr->left = curr->right = NULL;
    
    return newRoot;
}
