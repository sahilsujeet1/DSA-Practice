#include<iostream>
using namespace std;

class Node {
    public:

    int data;
    Node *next;

    Node(int value) {
        this->data = value;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        this->next = NULL;
        cout << "Memory freed for node with value: " << value << endl;
    }
};

void print(Node* &tail) {
    Node *temp = tail;
    if(temp == NULL) {
        cout << "No linked list found!" << endl;
    } else {
        cout << "Circular Linked List: ";
        do {
            cout << temp->data << " ";
            temp = temp->next;
        }
        while(temp != tail);
        cout << endl << endl;
    }

}

void insertNode(Node* &tail, int element, int d) {
    if(tail == NULL) {
        Node *newNode = new Node(d);
        newNode->next = newNode;
        tail = newNode;
    } else {
        Node *temp = tail;
        while(temp->data != element) {
            temp = temp->next;
        }
        Node *newNode = new Node(d);
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void deleteNode(Node* &tail, int element) {
    if(tail == NULL) {
        cout << "Cannot delete. No linked list found!" << endl;
    } else {
        Node *prev = tail;
        Node *curr = prev->next;

        while(curr->data != element) {
            prev = curr;
            curr = prev->next;
        }
        prev->next = curr->next;

        if(prev == curr) {
            tail = NULL;
        } else if (tail == curr) {
            tail = curr->next;
        }

        curr->next = NULL;
        delete curr;
    }
}

int main() {
    Node *node = new Node(2);
    node->next = node;
    Node *tail = node;

    print(tail);

    insertNode(tail, 2, 5);
    print(tail);
    insertNode(tail, 5, 7);
    print(tail);
    insertNode(tail, 7, 9);
    print(tail);
    insertNode(tail, 9, 4);
    print(tail);
    insertNode(tail, 2, 3);
    print(tail);
    deleteNode(tail, 7);
    print(tail);
    deleteNode(tail, 2);
    print(tail);
    deleteNode(tail, 4);
    print(tail);
}