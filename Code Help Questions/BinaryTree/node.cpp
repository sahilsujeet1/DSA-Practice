#include<bits/stdc++.h>
class Node {
    int data;
    Node *left, *right;

    public:
    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};