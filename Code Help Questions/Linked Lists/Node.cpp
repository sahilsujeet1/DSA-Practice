#include<iostream>

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
    while(head != NULL) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl << std::endl;
}
