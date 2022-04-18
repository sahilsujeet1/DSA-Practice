#include<bits/stdc++.h>
using namespace std;

class Node {
    public:

    int data;
    Node *left, *right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node *root) {
    cout << "Enter the data: ";
    int data;
    cin >> data;
    root = new Node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Left of " << root->data << endl;
    root->left = buildTree(root->left);
    cout << "Right of " << root->data << endl;
    root->right = buildTree(root->left);

    return root;
}

int main() {
    Node *root = NULL;

    // 1 2 3 -1 -1 4 5 -1 -1 -1 6 7 -1 -1 8 -1 -1
    buildTree(root);
}