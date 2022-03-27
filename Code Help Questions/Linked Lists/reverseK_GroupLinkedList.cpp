#include<bits/stdc++.h>
using namespace std;

class Node {
    
    public:
    int data;
    Node *next;

    Node(int value) {
        this -> data = value;
        this -> next = NULL;
    }
};

void print(Node* head) {

    if(head == NULL) {
        cout << "No node in linked list" << endl;
    }

    Node *temp = head;
    cout << "Linked List: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

Node* kReverse(Node *head, int k) {
    if(head == NULL) {
        return NULL;
    }

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;
    int count = 0;

    while(curr != NULL && count < k) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if(next != NULL) {
        head->next = kReverse(next, k);
    }

    return prev;
}

int main() {
    Node *node = new Node(2);
    node->next = new Node(4);
    node->next->next = new Node(6);
    node->next->next->next = new Node(8);
    node->next->next->next->next = new Node(10);

    Node *reversedHead = kReverse(node, 2);
    print(reversedHead);
    return 0;
}