#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
       //Your code here 
       if(root == NULL) {
           return NULL;
       }
       
       if(root->data == n1 || root->data == n2) {
           return root;
       }
       
       Node *left = lca(root->left, n1, n2);
       Node *right = lca(root->right, n1, n2);
       
       if(left && right) {
           return root;
       } else if(left && !right) {
           return left;
       } else if(!left && right) {
           return right;
       } else {
           return NULL;
       }
    }
};