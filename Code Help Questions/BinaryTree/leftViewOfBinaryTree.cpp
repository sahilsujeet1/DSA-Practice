#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

void solve(Node *root, vector<int> &ans, int lvl) {
    if(root == NULL)
        return;
        
    if(lvl == ans.size())
        ans.push_back(root->data);
        
    solve(root->left, ans, lvl+1);
    solve(root->right, ans, lvl+1);
    
}

vector<int> leftView(Node *root)
{
   // Your code here
    vector<int> ans;
    if(root == NULL)
        return ans;
    
    solve(root, ans, 0);
    return ans;
}