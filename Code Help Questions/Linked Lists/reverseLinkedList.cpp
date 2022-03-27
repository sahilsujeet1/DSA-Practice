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

Node *reverseLinkedList(Node* head) {
    if(head == NULL || head->next == NULL)
        return head;
    
    Node *prev = NULL;
    Node *curr = head;
    Node *forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
}

void reverseR(Node* &head, Node *prev, Node *curr) {
    if(curr == NULL) {
        head = prev;
        return;
    }

    Node *forward = curr->next;
    reverseR(head, curr, forward);
    curr->next = prev;
}

Node* reverseR2(Node *head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node *prev = NULL;
    Node *newHead = reverseR2(head->next);
    prev->next = newHead;
    return newHead;
}

Node* reverse(Node *head) {

    /*
    // Using recursion approach 1
    Node *curr = head;
    Node *prev = NULL;
    reverseR(head, prev, curr);
    return head;
    */

   // Using recursion approcah 2
    return reverseR2(head);

   /*
    // Using iteration
   return reverseLinkedList(head);
   */
}

void print(Node *head) {
    cout << "Linked List: ";
    while(head != NULL) {
        cout << head->data << "  ";
        head = head->next;
    }cout << endl << endl;
}

int main() {
    Node *node = new Node(2);
    
    node->next = new Node(4);
    node->next->next = new Node(6);
    node->next->next->next = new Node(8);
    node->next->next->next->next = new Node(10);

    Node *reverseHead = reverseLinkedList(node);
    print(reverseHead);
    return 0;
}