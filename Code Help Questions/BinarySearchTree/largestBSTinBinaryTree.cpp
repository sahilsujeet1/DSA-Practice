#include <bits/stdc++.h>
#include "node.cpp"

class info {
    public:
        int maxi, mini, size;
        bool isBST;
};

info solve(Node* root, int &ans) {
    if(root == NULL) {
        return {INT_MIN, INT_MAX, 0, true};
    }
    
    info left = solve(root->left, ans);
    info right = solve(root->right, ans);
    
    info curr;
    curr.maxi = max(root->data, right.maxi);
    curr.mini = min(root->data, left.mini);
    curr.size = left.size + right.size + 1;
    
    if(left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        curr.isBST = true;
    } else {
        curr.isBST = false;
    }
    
    if(curr.isBST) {
        ans = max(ans, curr.size);
    }
    
    return curr;
}

int largestBST(Node* root) 
{
    // Write your code here.
    int maxSize = 0;
    info temp = solve(root, maxSize);
    return maxSize;
}