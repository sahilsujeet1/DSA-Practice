#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

void removeDuplicate(Node *head) {
    if(head == NULL) return;

    Node *curr = head;
    while(curr != NULL) {

        if((curr->next != NULL) && curr->data == curr->next->data) {
            Node *nextNext = curr->next->next;
            Node *toDelete = curr->next;
            delete (toDelete);
            curr->next = nextNext;
            curr = curr->next;

        } else {
            curr = curr->next;
        }
    }
}

int main() 
{
    Node *node = new Node(2);
    node->next = new Node(4);
    node->next->next = new Node(4);
    node->next->next->next = new Node(8);
    node->next->next->next->next = new Node(8);

    cout << "Original Linked List: ";
    print(node);

    removeDuplicate(node);
    cout << "Linked List without duplicates: ";
    print(node);
    
}