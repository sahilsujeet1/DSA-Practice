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

bool searchBST(Node *root, int val) {
    if(root == NULL)
        return false;
    if(root->data == val)
        return true;
    else if(root->data > val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

bool iterativeSearchBST(Node *root, int val) {  // Uses constant space hence more efficient than recursivve approach
    if(root == NULL)
        return false;

    Node *temp = root;
    while(temp != NULL) {
        if(temp->data == val)
            return true;
        else if(temp->data > val)
            temp = temp->left;
        else
            temp = temp->right;
    }
    return false;
}

Node *minNode(Node *root) {
    Node *temp = root;
    while(temp->left != NULL) {
        temp = temp->left;
    }

    return temp;
}

Node *maxNode(Node *root) {
    Node *temp = root;
    while(temp->right != NULL) {
        temp = temp->right;
    }

    return temp;
}

Node *deleteNode(Node *root, int val) {
    if(root == NULL)
        return root;

    if(root->data == val) {
        // 0 child
        if(!root->left && !root->right) {
            delete root;
            return NULL;
        }
        // Single Child
        // Left only child
        if(root->left && !root->right) {
            Node *temp = root->left;
            delete root;
            return temp;
        }

        // Right only child
        if(!root->left && root->right) {
            Node *temp = root->right;
            delete root;
            return temp;
        }

        // Two children
        if(root->left && root->right) {
            int mini = minNode(root->right)->data;
            root->data = mini;
            root->right = deleteNode(root->right, mini);
            return root;
        }

    } else if(root->data > val)
        root->left = deleteNode(root->left, val); // Add left subtree to root after deletion in left part
    else
        root->right = deleteNode(root->right, val); // Add right subtree to root after deletion in right part
    return root;
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

    int x;
    // cout << "\nEnter a value to search in BST: ";
    // cin >> x;
    // cout << x << " is present in BST: " << (iterativeSearchBST(root, x) ? "YES" : "NO") << endl;
    // cout << x << " is present in BST: " << (searchBST(root, x) ? "YES" : "NO") << endl;

    cout << "Min node in BST: " << minNode(root)->data << endl;
    cout << "Max node in BST: " << maxNode(root)->data << endl;

    cout << "\nEnter a node to delete: ";
    cin >> x;
    root = deleteNode(root, x);
    cout << "Level order after deletion: " << endl;
    levelOrderTraversal(root);

    return 0;
}