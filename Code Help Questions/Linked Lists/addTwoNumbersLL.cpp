#include<iostream>
#include "Node.cpp"
using namespace std;

Node *reverse(Node *head) {
    if(head == NULL)
        return NULL;

    Node *curr = head;
    Node *prev = NULL;
    Node *next = NULL;

    while(curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

void insertTail(Node* &head, Node* &tail, int val) {
    Node *node = new Node(val);

    if(head == NULL) {
        head = node;
        tail = node;
    }

    tail->next = node;
    tail = tail->next;
}

Node *addTwoLL(Node *num1, Node *num2) {
    int carry = 0;
    num1 = reverse(num1);
    num2 = reverse(num2);
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    while(num1 != NULL || num2 != NULL || carry != 0) {
        int val1 = 0, val2 = 0;
        if(num1 != NULL)
            val1 = num1->data;

        if(num2 != NULL)
            val2 = num2->data;

        int sum = val1 + val2 + carry;
        int digit = sum%10;
        insertTail(ansHead, ansTail, digit);
        carry = sum/10;

        if(num1 != NULL)
            num1 = num1->next;

        if(num2 != NULL)
            num2 = num2->next;
    }
    ansHead = reverse(ansHead);
    return ansHead;
}

int main() {
    Node *num1 = new Node(4);
    num1->next = new Node(5);
    cout << "First number: ";
    print(num1);

    Node *num2 = new Node(2);
    num2->next = new Node(7);
    num2->next->next = new Node(9);
    cout << "Second number: ";
    print(num2);

    cout << "Sum: ";
    Node *result = addTwoLL(num1, num2);
    print(result);
}