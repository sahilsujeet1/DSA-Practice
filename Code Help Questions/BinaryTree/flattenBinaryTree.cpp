#include<bits/stdc++.h>
#include<node.cpp>

// Flatten binary tree using Morris traversal technique
// GFG hard level question

class Solution
{
    public:
    void flatten(Node *root)
    {
        //code here
        Node *curr = root;
        while(curr != NULL) {
            if(curr -> left) {
                Node *pred = curr->left;
                while(pred->right)
                    pred = pred->right;
                
                pred->right = curr->right;
                curr->right = curr->left;
                curr->left = NULL;
            }
            curr = curr->right;
        }
    }
};