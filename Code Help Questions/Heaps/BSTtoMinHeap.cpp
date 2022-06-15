#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

void getInorder(Node* root, vector<int> &inorder) {
    if(root == NULL)
        return;
    getInorder(root->left, inorder);
    inorder.push_back(root->data);
    getInorder(root->right, inorder);
}

void preOrder(Node* root, vector<int> &inorder, int &i) {
    if(root == NULL)
        return;
    root->data = inorder[i++];
    preOrder(root->left, inorder, i);
    preOrder(root->right, inorder, i);
}

Node* convertBST(Node* root)
{
	// Write your code here.
    vector<int> inorder;
    getInorder(root, inorder);
    Node* temp = root;
    int i = 0;
    preOrder(temp, inorder, i);
    
    return root;
}