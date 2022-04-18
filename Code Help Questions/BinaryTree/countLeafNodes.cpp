#include<bits/stdc++.h>
#include "node.cpp"
using namespace std;

void inorder(Node *root, int &count) {
    if(root == NULL)
        return;
    
    inorder(root->left, count);
    if(!root->left && !root->right)
        count++;
    inorder(root->right, count);
}

int countLeaves(Node *root) {
    int count = 0;
    inorder(root, count);
    return count;
}

int main() {
    Node *root = NULL;

    buildFromLevelOrder(root);
    cout << "Number of leaf nodes: " << countLeaves(root) << endl;

    return 0;
}