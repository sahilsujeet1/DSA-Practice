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

int main() {
    Node *root = NULL;

    // 1 2 3 -1 -1 4 5 -1 -1 -1 6 7 -1 -1 8 -1 -1
    root = buildTree(root);

    cout << "\nLevel Order Traversal: " << endl;
    levelOrderTraversal(root);
}