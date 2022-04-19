#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

pair<bool, int> isSumFast(Node *root) {
    if(root == NULL) {
        pair<bool,int> p = make_pair(true, 0);
        return p;
    }
    
    if(!root->left && !root->right) {
        pair<bool,int> p = make_pair(true, root->data);
        return p;
    }
    
    pair<bool, int> left = isSumFast(root->left);
    pair<bool, int> right = isSumFast(root->right);
    
    bool isTrue = left.second + right.second == root->data;
    
    pair<bool, int> ans;
    
    
    if(left.first && right.first && isTrue) {
        ans.first = true;
        ans.second = 2 * root->data;
    } else{
        ans.first = false;
    }
    
    return ans;
}

bool isSumTree(Node* root)
{
        // Your code here
        return isSumFast(root).first;
}