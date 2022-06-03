#include <bits/stdc++.h>
#include "node.cpp"
pair<int,int> predecessorSuccessor(Node* root, int key)
{
    // Write your code here.
    Node* temp = root;
    int pred = -1;
    int succ = -1;
    
    while(temp->data != key) {
        if(key > temp->data) {
            pred = temp->data;
            temp = temp->right;
        }
        else {
            succ = temp->data;
            temp = temp->left;
        }
    }
    
    // Max of Left subtree
    Node* leftTree = temp->left;
    while(leftTree != NULL) {
        pred = leftTree->data;
        leftTree = leftTree->right;
    }
    
    // Min of Right subtree
    Node* rightTree = temp->right;
    while(rightTree != NULL) {
        succ = rightTree->data;
        rightTree = rightTree->left;
    }
    
    pair<int, int> ans = make_pair(pred, succ);
    return ans;
}