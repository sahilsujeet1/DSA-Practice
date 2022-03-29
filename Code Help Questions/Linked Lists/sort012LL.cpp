#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *sortLL1(Node *head) {
    int zero = 0, one = 0, two = 0;

    Node *curr = head;
    while(curr != NULL) {
        int value = curr->data;
        if(value == 0) {
            zero++;
        } else if(value == 1) {
            one++;
        } else if(value == 2) {
            two++;
        }
        curr = curr->next;
    }

    curr = head;
    while(curr != NULL) {
        if(zero != 0) {
            curr->data = 0;
            zero--;
        } else if(one != 0) {
            curr->data = 1;
            one--;
        } else if(two != 0) {
            curr->data = 2;
            two--;
        }
        curr = curr->next;
    }

    return head;
}

void insertTail(Node* &tail, Node *curr) {
    tail->next = curr;
    tail = curr;
}

Node* sortLL2(Node *head) {
    Node *zeroHead = new Node(-1);
    Node *oneHead = new Node(-1);
    Node *twoHead = new Node(-1);
    Node *zeroTail = zeroHead;
    Node *oneTail = oneHead;
    Node *twoTail = twoHead;

    Node *curr = head;
    while(curr != NULL) {
        if(curr->data == 0) {
            insertTail(zeroTail, curr);
        } else if(curr->data == 1) {
            insertTail(oneTail, curr);
        } else if(curr->data == 2) {
            insertTail(twoTail, curr);
        }
        curr = curr->next;
    }

    if(oneHead->next != NULL) {
        zeroTail->next = oneHead->next;
    } else {
        zeroTail->next = twoHead->next;
    }

    oneTail->next = twoHead->next;
    twoTail->next = NULL;

    head = zeroHead->next;
    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}

int main() {
    Node* node = new Node(2);
    node->next = new Node(1);
    node->next->next = new Node(2);
    node->next->next->next = new Node(0);
    node->next->next->next->next = new Node(1);
    node->next->next->next->next->next = new Node(1);
    node->next->next->next->next->next->next = new Node(0);
    node->next->next->next->next->next->next->next = new Node(2);

    cout << "Original LL: ";
    print(node);

    Node *sortedHead1 = sortLL1(node);
    cout << "\nSorted LL: ";
    print(sortedHead1);

    Node *sortedHead2 = sortLL2(node);
    cout << "\nSorted LL: ";
    print(sortedHead2);
}