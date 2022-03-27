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

void print(Node *head) {
    cout << "Linked List: ";
    while(head != NULL) {
        cout << head->data << "  ";
        head = head->next;
    }cout << endl << endl;
}

int getLength(Node *head) {
    int len = 0;
    while(head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}

Node* midLL(Node *head) {
    int mid = getLength(head)/2;

    for(int i=0; i<mid; i++) {
        head = head->next;
    }

    return head;
}

Node* midLL2(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL)
            fast = fast->next;
        slow = slow->next;
    }

    return slow;
}

int main() {
    Node *node = new Node(2);
    
    node->next = new Node(4);
    node->next->next = new Node(6);
    node->next->next->next = new Node(8);
    node->next->next->next->next = new Node(10);
    node->next->next->next->next->next = new Node(12);

    Node *mid = midLL(node);
    cout << "Middle node: " << mid->data << endl;
    Node *mid2 = midLL2(node);
    cout << "Middle node two pointer: " << mid2->data << endl;
    return 0;
}