#include <bits/stdc++.h>
#include "node.cpp"

int solve(Node* root, int &i, int k) {
    if(root == NULL)
        return -1;
    
    // Left
    int left = solve(root->left, i, k);
    if(left != -1)
        return left;
    // Root
    i++;
    if(i == k)
        return root->data;
    
    // Right
    return solve(root->right, i , k);
}

int kthSmallest(Node* root, int k) {
    // Write your code here.
    int i = 0;
    return solve(root, i, k);
    
}

/*
    For kth Largest we can use
    k = (n-k+1)
    in the above method
*/