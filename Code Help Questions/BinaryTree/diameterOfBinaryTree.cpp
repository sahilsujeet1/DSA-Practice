#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

pair<int,int> diameterFast(Node *root) {
    if(root == NULL) {
        pair<int, int> p = make_pair(0,0);
        return p;
    }
        
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);
    
    int leftAns = left.first;
    int rightAns = right.first;
    int combo = left.second + right.second + 1;
    
    pair<int,int> ans;
    ans.first = max(leftAns, max(rightAns, combo));
    ans.second = max(left.second, right.second) + 1;
    
    return ans;
}

int diameter(Node* root) {
    // Your code here
    return diameterFast(root).first;
}