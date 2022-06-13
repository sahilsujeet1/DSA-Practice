#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

class Solution {
  public:
  
    int countNodes(Node* root) {
        if(root ==  NULL)
            return 0;
        
        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return 1+left+right;
    }
  
    bool isCBT(Node* root, int i, int count) {
        if(root == NULL)
            return true;
        
        if(i >= count) {
            return false;
        } else {
            bool left = isCBT(root->left, 2*i+1, count);
            bool right = isCBT(root->right, 2*i+2, count);
            return (left && right);
        }
    }
    
    bool isMaxOrder(Node* root) {
        if(!root->left && !root->right)
            return true;
            
        if(!root->right) {
            return (root->data > root->left->data);
        } else {
            bool left = isMaxOrder(root->left);
            bool right = isMaxOrder(root->right);
                
            return (left && right && (root->data > root->left->data && root->data > root->right->data));
        }
    }
  
    bool isHeap(Node* tree) {
        // code here
        int index = 0;
        int totalCount = countNodes(tree);

        return (isCBT(tree,index,totalCount) && isMaxOrder(tree));
    }
};
