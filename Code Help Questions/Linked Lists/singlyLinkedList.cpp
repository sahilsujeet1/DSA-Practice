#include<iostream>
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

void print(Node* &head, Node* &tail) {

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
    cout << "head: " << head->data << "\t Tail: " << tail->data << endl << endl;
}

int getLength(Node* &head) {
    Node *temp = head;
    int cnt = 0;
    while(temp != NULL) {
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void insertHead(Node* &head, int d) {
    Node *temp = new Node(d);

    temp->next = head;
    head = temp;
}

void insertTail(Node* &tail, int d) {
    Node* temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {

    if(pos == 1) {
        insertHead(head, d);
        return;
    }

    if(pos == getLength(head)+1) {
        insertTail(tail, d);
        return;
    }

    int cnt = 1;
    Node *temp = head;

    while(cnt < pos-1) {
        temp = temp->next;
        cnt++;
    }

    Node *node = new Node(d);
    node->next = temp->next;
    temp->next = node;
}

void deleteHead(Node* &head) {
    Node* temp = head;
    head = temp->next;
    temp = NULL;
    delete temp;
}

void deleteTail(Node* &tail) {
    Node* temp = tail;
    tail = temp->next;
    temp = NULL;
    delete temp;
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    int cnt = 1;
    Node *prev = head;
    Node *curr = head;

    if(pos == 1) {
        deleteHead(head);
        return;
    } else {
        while(cnt < pos-1) {
            prev = prev->next;
            cnt++;
        }
        curr = prev->next;

        prev->next = curr->next;
        curr->next = NULL;
        delete curr;

        if(cnt == getLength(head)) {
            tail = prev;
        }
    }
}

int main() 
{
    Node *node = new Node(2);
    Node* head = node;
    Node *tail = node;
    insertHead(head, 4);
    // print(head, tail);
    insertHead(head, 6);
    // print(head, tail);
    insertHead(head, 8);
    cout << "length: " << getLength(head) << endl;
    // print(head, tail);
    insertHead(head, 10);
    // print(head, tail);
    insertTail(tail, 12);
    // print(head, tail);
    insertTail(tail, 14);
    // print(head, tail);

    insertAtPosition(head, tail, 1, 100);
    // print(head, tail);
    insertAtPosition(head, tail, 3, 200);
    // print(head, tail);
    insertAtPosition(head, tail, 10, 300);
    print(head, tail);

    deleteNode(head, tail, 10);
    print(head, tail);
}