#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

Node *insertIntoBST(Node *root, int val) {
    if(root == NULL) {
        root = new Node(val);
        return root;
    }

    if(root->data < val) {
        root->right = insertIntoBST(root->right, val);
    } else {
        root->left = insertIntoBST(root->left, val);
    }

    return root;
}

void takeInput(Node* &root) {
    int data;
    cin >> data;

    while(data != -1) {
        root = insertIntoBST(root, data);
        cin >> data;
    }

}

int main() {
    Node *root = NULL;

    cout << endl << "Enter nodes to insert into BST: ";
    takeInput(root);

    cout << endl << "Level order: " << endl;
    levelOrderTraversal(root);

    cout << endl << "Inorder: " << endl;
    inorderTraversal(root);

    cout << endl << "Preorder: " << endl;
    preorderTraversal(root);

    cout << endl << "Postorder: " << endl;
    postorderTraversal(root);
    cout << endl;
}