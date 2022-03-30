#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *solve(Node *first, Node *second) {

    if(first->next == NULL) {
        first->next = second;
        return first;
    }

    Node *curr1 = first;
    Node *next1 = curr1->next;
    Node *curr2 = second;
    Node *next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL) {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            
            curr1 = curr2;
            curr2 = next2;

        } else {
            curr1 = curr1->next;
            next1 = next1->next;

            if(next1 == NULL) {
                curr1->next = curr2;
                return first;
            }
        }
    }

    return first;
}

Node *mergeSortedLL(Node *first, Node *second) {
    if(first == NULL)
        return second;
    if(second == NULL) 
        return first;

    if(first->data < second->data) {
        return solve(first, second);
    } else {
        return solve(second, first);
    }
}

int main() {
    Node *node1 = new Node(1);
    node1->next = new Node(9);
    node1->next->next = new Node(12);
    Node *head1 = node1;

    Node *node2 = new Node(6);
    node2->next = new Node(10);
    node2->next->next = new Node(11);
    Node *head2 = node2;

    Node *result = mergeSortedLL(head1, head2);
    print(result);
}