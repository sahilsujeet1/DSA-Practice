#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

class Solution {
private:
    void traverseLeft(Node *root, vector<int> &ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
            
        ans.push_back(root->data);
        if(root->left)
            traverseLeft(root->left, ans);
        else
            traverseLeft(root->right, ans);
        
    }
    
    void traverseLeaf(Node *root, vector<int> &ans) {
        if(root == NULL)
            return;
            
        if(root->left == NULL && root->right == NULL) {
            ans.push_back(root->data);
            return;
        }
            
        traverseLeaf(root->left, ans);
        traverseLeaf(root->right, ans);
    }
    
    void traverseRight(Node *root, vector<int> &ans) {
        if((root == NULL) || (root->left == NULL && root->right == NULL))
            return;
            
        if(root->right)
            traverseRight(root->right, ans);
        else
            traverseRight(root->left, ans);
        
        ans.push_back(root->data);
    }
    
public:
    vector <int> boundary(Node *root)
    {
        //Your code here
        vector <int> ans;
        if(root ==  NULL)
            return ans;
        
        ans.push_back(root->data);
        
        // Traverse left
        traverseLeft(root->left, ans);
        
        // Traverse leaf nodes
        // Left subtree
        traverseLeaf(root->left, ans);
        
        // Right subtree
        traverseLeaf(root->right, ans);
        
        // Traverse Right
        traverseRight(root->right, ans);
        
        return ans;
    }
};
