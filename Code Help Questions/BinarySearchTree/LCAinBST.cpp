#include <bits/stdc++.h>
#include "node.cpp"

Node* LCAinaBST(Node* root, Node* P, Node* Q)
{
	// Write your code hereif
    if(root == NULL)
        return NULL;
    
    if(P->data < root->data && Q->data < root->data)
        return LCAinaBST(root->left, P, Q);
    else if (P->data > root->data && Q->data > root->data)
        return LCAinaBST(root->right, P, Q);
    else
        return root;
}