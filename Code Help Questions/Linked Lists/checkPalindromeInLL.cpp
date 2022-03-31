#include<bits/stdc++.h>
#include "Node.cpp"
using namespace std;

class Solution1 {
    // Copy linked list to an array and check for palindrome
    // Time complexity: O(n)        Space Complexity: O(n)
    public:
    bool isPalindrome(Node *head) {
        vector<int> arr;

        Node *temp = head;
        while(temp != NULL) {
            arr.push_back(temp->data);
            temp = temp->next;
        }

        int s=0, e=arr.size()-1;
        while(s < e) {
            if(arr[s++] != arr[e--])
                return false;
        }
        return true;
    }
};

class Solution2 {
    // Get the mid node of linked list and create two linked list
    // Reverse second linked list and compare each value with other list and return answer
    // Time complexity: O(n)        Space complexity: O(1)
    Node *getMid(Node *head) {
        Node *slow = head;
        Node *fast = head->next;

        while(fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    Node *reverseLL(Node *head) {
        if(head == NULL || head->next == NULL) {
            return head;
        }

        Node *curr = head;
        Node *prev = NULL;
        Node *next = NULL;

        while(curr->next != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    bool isPalindrome(Node *head) {
        
        if(head->next == NULL) {
            return true;
        }
        
        Node *mid = getMid(head);
        Node *temp = mid->next;
        mid->next= reverseLL(temp);
        Node *head1 = head;
        Node *head2 = mid->next;

        while(head2 != NULL) {
            if(head1->data == head2->data) {
                head1 = head1->next;
                head2 = head2->next;
            } else {
                return false;
            }
        }

        return true;
    }
};

void insertTail(Node* &tail, int d) {
    Node* temp = new Node(d);

    tail->next = temp;
    tail = temp;
}

int main() {
    Node *node = new Node(1);
    Node *head = node;
    Node *tail = node;
    insertTail(tail, 2);
    insertTail(tail, 3);
    insertTail(tail, 3);
    insertTail(tail, 2);
    insertTail(tail, 1);

    cout << "Original Linked List: ";
    print(head);

    Solution1 s1;
    cout << "Is Linked List Palindrome: " << (s1.isPalindrome(head) ? "Yes" : "No") << endl;
    Solution1 s2;
    cout << "Is Linked List Palindrome: " << (s2.isPalindrome(head) ? "Yes" : "No") << endl;
}