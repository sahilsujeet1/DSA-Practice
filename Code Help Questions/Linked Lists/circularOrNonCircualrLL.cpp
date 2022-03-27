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

bool checkCircular(Node *head) {
    if(head == NULL) {
        return true;
    }

    Node *temp = head;
    while(temp != NULL && temp->next != head) {
        temp = temp->next;
    }

    if(temp == NULL) 
        return false;

    return true;
}

int main() 
{
    Node *node = new Node(2);
    node->next = new Node(4);
    node->next->next = new Node(6);
    node->next->next->next = new Node(8);
    node->next->next->next->next = new Node(10);

    // Makes LL circular
    // node->next->next->next->next = node;

    if(checkCircular(node)) {
        cout << "\nLinked list is circular." << endl << endl;
    } else {
        cout << "\nLinked list is not circular." << endl << endl;
    }
}