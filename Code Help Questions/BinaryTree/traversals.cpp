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

void levelOrderTraversal(Node *root) {
    if(root) {
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()) {
            Node *temp = q.front();
            q.pop();

            if(temp == NULL) {
                cout << endl; // traversed last level completely
                if(!q.empty()) {
                    q.push(NULL); //queue still has some nodes
                }
            } else {
                cout << temp->data << " ";

                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
    } else {
        cout << "Tree root is unavailable" << endl;
    }
}

void buildFromLevelOrder(Node* &root) {
    cout << "Enter root value: ";
    int data;
    cin >> data;

    root = new Node(data);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node *temp = q.front();
        q.pop();

        cout << "Enter value for left of " << temp->data << ": ";
        cin >> data;
        if(data != -1) {
            temp->left = new Node(data);
            q.push(temp->left);
        }

        cout << "Enter value for right of " << temp->data << ": ";
        cin >> data;
        if(data != -1) {
            temp->right = new Node(data);
            q.push(temp->right);
        }
    }

}

void preorderTraversal(Node *root) {
    if(root == NULL)
        return;
    
    cout << root->data << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(Node *root) {
    if(root == NULL)
        return;
    
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void postorderTraversal(Node *root) {
    if(root == NULL)
        return;
    
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    Node *root = NULL;

    // 1 2 3 -1 -1 4 5 -1 -1 -1 6 7 -1 -1 8 -1 -1
    root = buildTree(root);

    cout << "\nLevel Order Traversal: " << endl;
    levelOrderTraversal(root);
    cout << "\nPreorder Traversal: " << endl;
    preorderTraversal(root);
    cout << "\nInOrder Traversal: " << endl;
    inorderTraversal(root);
    cout << "\nPostOrder Traversal: " << endl;
    postorderTraversal(root);
    cout << endl;

    root = NULL;
    buildFromLevelOrder(root);

    cout << "\nLevel Order Traversal: " << endl;
    levelOrderTraversal(root);

    return 0;
}