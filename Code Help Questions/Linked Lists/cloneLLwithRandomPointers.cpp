#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node *next, *random;

    Node(int d) {
        data = d;
        next = NULL;
        random = NULL;
    }
};

void insertTail(Node* &head, Node* &tail, int val) {
    Node *node = new Node(val);
    if(head == NULL) {
        head = node;
        tail = node;
    } else {
        tail->next = node;
        tail = tail->next;
    }
}
void print(Node *head) {
    Node *temp = head;

    while(temp != NULL) {
        cout << temp->data << " -> " << (temp->random ? to_string(temp->random->data) : "NULL" ) << endl;
        temp = temp->next;
    } cout << endl << endl;
}


class Sol1 {
    /*
        Copies nodes to clone
        Counts the position of random node in original node from head
        Loops till the position is reached by clone LL
        Updates the node->random with random node

        Time Complexity: O(n^2)         Space Complexity: O(1)
    */
    public:
    Node *cloneLL(Node *head) {
        if(head == NULL)
            return NULL;

        Node *cloneHead = NULL;
        Node *cloneTail = NULL;
        Node *temp = head;

        while(temp != NULL) {
            insertTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }

        temp = head;
        Node *cloneTemp = cloneHead;
        while(temp != NULL) {
            
            if(temp->random != NULL) {
                int randomPos = 0;
                Node *curr = head;
                while(curr != temp->random) {
                randomPos++;
                curr = curr->next;
                }

                int cnt = 0;
                curr = cloneHead;
                while(cnt < randomPos) {
                    curr = curr->next;
                    cnt++;
                }
                cloneTemp->random = curr; 
            }
            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }
        return cloneHead;
    }
};

class Sol2 {
    /*
        Copies nodes to clone LL
        Map the original linked list to clone linked list
        Loop again original LL and set clone node->random to value from map with key original node->random

        Time Complexity: O(n)       Space Complexity: O(n)
    */
    public:
    Node *cloneLL(Node *head) {
        Node *temp = head;
        Node *cloneHead = NULL;
        Node *cloneTail = NULL;

        unordered_map<Node*, Node*> oldToNew;

        while(temp != NULL) {
            insertTail(cloneHead, cloneTail, temp->data);
            oldToNew[temp] = cloneTail;
            temp = temp->next;
        }

        temp = head;
        Node *cloneTemp = cloneHead;
        while(temp != NULL) {
            if(temp->random != NULL)
                cloneTemp->random = oldToNew[temp->random];
            temp = temp->next;
            cloneTemp = cloneTemp->next;
        }

        return cloneHead;
    }
};

int main() {
    Node *node = new Node(1);
    Node *head = node;
    node->next = new Node(3);
    node->next->next = new Node(5);
    node->next->next->next = new Node(7);
    node->next->next->next->next = new Node(9);
    node->random = node->next->next->next;
    node->next->random = node;
    node->next->next->next->next->random = node->next->next ;

    cout << "Original LL: " << endl;
    print(head);
    Sol1 s1;
    Node *cloned = s1.cloneLL(head);
    cout << "Cloned LL with Approach 1: " << endl;
    print(cloned);

    Sol2 s2;
    cloned = s2.cloneLL(head);
    cout << "Cloned LL with Approach 2: " << endl;
    print(cloned);

}