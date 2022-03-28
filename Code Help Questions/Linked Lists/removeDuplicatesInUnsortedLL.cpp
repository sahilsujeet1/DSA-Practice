#include <iostream>
#include "Node.cpp"
using namespace std;

void removeDuplicate1(Node *head) {
    if(head == NULL)    
        return;

    Node *curr = head;

    while(curr != NULL) {
        Node *temp = curr->next;
        Node *prev = curr;

        while(temp != NULL) {
            if(temp->data == curr->data) {
                prev->next = temp->next;
                Node *toDelete = temp;
                temp = temp->next;
                delete toDelete;
            } else {
                prev = prev->next;
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
}

int main() {
    Node *node = new Node(2);
    Node *head = node;
    node->next = new Node(4);
    node->next->next = new Node(3);
    node->next->next->next = new Node(2);
    node->next->next->next->next = new Node(6);
    node->next->next->next->next->next = new Node(8);
    node->next->next->next->next->next->next = new Node(2);
    node->next->next->next->next->next->next->next = new Node(8);
    cout << "Original Linked List: ";
    print(node);

    removeDuplicate1(node);
    cout << "Linked list without duplicates: ";
    print(node);
}