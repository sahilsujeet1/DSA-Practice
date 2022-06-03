#include <bits/stdc++.h>
#include "node.cpp"

bool isBST(Node *root, int minn, int maxx) {
    if(!root)
        return true;
    
    if(root->data >= minn && root->data <= maxx) {
        bool left = isBST(root->left, minn, root->data);
        bool right = isBST(root->right, root->data, maxx);

        return left && right;
    }
    
    return false;
}


bool validateBST(Node *root) {
    return isBST(root, INT_MIN, INT_MAX);
}