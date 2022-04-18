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