#include <bits/stdc++.h>
#include "Node.cpp"
using namespace std;

Node *getMid(Node *head) {
    Node *slow = head;
    Node *fast = head->next;

    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }

    return slow;
}

Node *merge(Node *left, Node *right) {
    if(left == NULL)
        return right;
    if(right == NULL)
        return left;

    Node *merged = new Node(-1);
    Node *temp = merged;

    while(left != NULL && right != NULL) {
        if(left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }
    
    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }

    merged = merged->next;
    return merged;

}

Node *mergeSort(Node *head) {
    if(head == NULL || head->next == NULL)
        return head;


    Node *mid = getMid(head);
    Node *left = head;
    Node *right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node *ans = merge(left, right);
    return ans;
}

int main()
{
    Node *node = new Node(5);
    Node *head = node;
    node->next = new Node(2);
    node->next->next = new Node(8);
    node->next->next->next = new Node(4);
    node->next->next->next->next = new Node(1);

    cout << "\nOriginal LL: ";
    print(head);

    cout << "Sorted linked list: ";
    Node *sortedLL = mergeSort(head);
    print(sortedLL);
}