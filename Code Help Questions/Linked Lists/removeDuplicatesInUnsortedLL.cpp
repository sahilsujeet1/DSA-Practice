#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

// Using two loops
// Time complexity: O(n^2)      Space complexity: O(1)
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

// Using unordered set
// Time Complexity: O(n)        Space Complexity: O(n)
void removeDuplicate2(Node *head) {
    if(head == NULL)
        return;
    
    unordered_set<int> visited;
    Node *curr = head;
    Node *prev = NULL;

    while(curr != NULL) {
        if(visited.find(curr->data) != visited.end()) {
            Node *toDelete = curr;
            prev->next = curr->next;
            curr = curr->next;
            delete toDelete;
        } else {
            visited.insert(curr->data);
            prev = curr;
            curr = curr->next;
        }
    }
}

// Using merge sort to sort and then remove duplicate from sorted LL
// Time Complexity: O(nlogn)        Space Complexity: O(1)
void removeDuplicate(Node *head) {

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

    removeDuplicate2(node);
    cout << "Linked list without duplicates: ";
    print(node);
}