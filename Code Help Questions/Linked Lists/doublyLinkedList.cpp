#include<iostream>
using namespace std;

class Node {
    public:

    int data;
    Node *prev;
    Node *next;

    Node(int value) {
        this->data = value;
        this->prev = NULL;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        this->next = NULL;
        this->prev = NULL;

        cout << "Memory freed for node with value: " << value << endl;
    }
};

void print(Node* &head, Node* &tail) {
    Node *temp = head;

    cout << "Doubly Linked List: ";
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    } cout << endl;
    cout << "Head: " << head->data << "\tTail: " << tail->data << endl << endl;
}

int getLength(Node* &head) {
    Node *temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;
        temp = temp->next;
    }

    return cnt;
}

void insertHead(Node* &head, int d) {
    Node *temp = head;
    Node *nodeToInsert = new Node(d);
    
    nodeToInsert->next = head;
    head->prev = nodeToInsert;
    head = nodeToInsert;

}

void insertTail(Node* &tail, int d) {
    Node *temp = tail;
    Node *newNode = new Node(d);

    temp->next = newNode;
    newNode->prev = temp;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d) {
    Node *temp = head;
    int cnt = 1;

    if(pos == 1) {
        insertHead(head, d);
    } else if(pos == getLength(head)+1) {
        insertTail(tail, d);
    } else {
        while(cnt != pos-1) {
            temp = temp->next;
            cnt++;
        }

        Node *node = new Node(d);
        node->next = temp->next;
        node->prev = temp;
        temp->next = node;
    }
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    
    if(pos == 1) {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete temp;
    } else {
        Node *prev = NULL;
        Node *curr = head;
        int cnt = 0;
        while(cnt < pos-1) {
            prev = curr;
            curr = prev->next;
            cnt++;
        }

        if(curr == tail) {
            tail = prev;
        }
        curr->prev = NULL;
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    
}

int main() {
    Node *node = new Node(2);
    Node *head = node;
    Node *tail = node;
    print(head, tail);
    insertHead(head, 0);
    print(head, tail);
    insertTail(tail, 4);
    print(head, tail);
    insertHead(head, 5);
    print(head, tail);
    insertAtPosition(head, tail, 2, 6);
    print(head, tail);
    insertAtPosition(head, tail, 5, 7);
    print(head, tail);
    insertAtPosition(head, tail, 7, 8);
    print(head, tail);
    insertAtPosition(head, tail, 1, 9);
    print(head, tail);
    deleteNode(head, tail, 1);
    print(head, tail);
    deleteNode(head, tail, 7);
    print(head, tail);

    return 0;
}