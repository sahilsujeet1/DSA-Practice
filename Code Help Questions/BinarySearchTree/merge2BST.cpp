#include<bits/stdc++.h>
#include "node.cpp"

class Approach1 {
  public:
    void inorder(Node *root, vector<int> &in) {
        if(root == NULL)
            return;
        inorder(root->left, in);
        in.push_back(root->data);
        inorder(root->right, in);
    }
    
    vector<int> mergeTwoSortedArr(vector<int> arr1, vector<int> arr2) {
        vector<int> ans;
        int i=0, j=0;
        while(i < arr1.size() && j < arr2.size()) {
            if(arr1[i] < arr2[j]) {
                ans.push_back(arr1[i++]);
            } else {
                ans.push_back(arr2[j++]);
            }
        }
        
        while(i < arr1.size())
            ans.push_back(arr1[i++]);
        
        while(j < arr2.size())
            ans.push_back(arr2[j++]);
        
        return ans;
    }
    
    Node *inorderToBST(int s, int e, vector<int> &in) {
        if(s > e)
            return NULL;
        
        int mid = (s+e)/2;
        Node *root = new Node(in[mid]);
        root->left = inorderToBST(s, mid-1, in);
        root->right = inorderToBST(mid+1, e, in);
        
        return root;
    }
    
    Node *findAns(Node *root1, Node *root2) {
        vector<int> in1, in2;
        inorder(root1, in1);
        inorder(root2, in2);
        
        vector<int> mergedArr = mergeTwoSortedArr(in1, in2);
        return inorderToBST(0, mergedArr.size()-1, mergedArr);
    }
};


class Approach2 {
  public:
    void BSTtoDLL(Node *root, Node* &head) {
        if(root == NULL)
            return;
        
        BSTtoDLL(root->right, head);
        
        root->right = head;
        if(head != NULL)
            head->right = root;
        head = root;
        
        BSTtoDLL(root->left, head);
    }
    
//      Node *mergeLogic(Node  *first, Node  *second) {

//         if(first->right == NULL) {
//             first->right = second;
//             return first;
//         }

//         Node *curr1 = first;
//         Node *next1 = curr1->right;
//         Node *curr2 = second;
//         Node *next2 = curr2->right;

//         while(next1 != NULL && curr2 != NULL) {
//             if((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
//                 curr1->right = curr2;
//                 next2 = curr2->right;
//                 curr2->right = next1;

//                 curr1 = curr2;
//                 curr2 = next2;

//             } else {
//                 curr1 = curr1->right;
//                 next1 = next1->right;

//                 if(next1 == NULL) {
//                     curr1->right = curr2;
//                     return first;
//                 }
//             }
//         }

//         return first;
//     }
    
    Node *mergeTwoSortedDLL(Node *head1, Node *head2) {
        Node *head = NULL;
        Node *tail = NULL;
        
//         if(head1->data < head2->data) {
//             return mergeLogic(head1, head2);
//         } else {
//             return mergeLogic(head2, head1);
//         }
        
        while(head1 != NULL && head2 != NULL) {
            if(head1->data < head2->data) {
                if(head == NULL) {
                    head = head1;
                } else {
                    tail->right = head1;
                    head1->left = tail;
                }
                tail = head1;
                head1 = head1->right;
            } else {
                if(head == NULL) {
                    head = head2;
                } else {
                    tail->right = head2;
                    head2->left = tail;
                }
                tail = head2;
                head2 = head2->right;
            }
        }
        
        while(head1 != NULL) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        }
        
        while(head2 != NULL) {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
        
        return head;
    }
    
    int countNodes(Node *root) {
        int cnt = 0;
        Node *temp = root;
        while(temp != NULL) {
            cnt++;
            temp = temp->right;
        }
        return cnt;
    }
    
    Node *DLLtoBST(Node* &root, int n) {
        if(n <= 0 || root == NULL)
            return NULL;
        
        Node *left = DLLtoBST(root->left, n/2);
        Node *head = root;
        head->left = left;
        
        root = root->right;
        
        Node *right = DLLtoBST(root->right, n/2-1);
        head->right = right;
        
        return head;
    }
        
    Node *findAns(Node *root1, Node *root2) {
        Node *ll1 = NULL;
        BSTtoDLL(root1, ll1);
        
        Node *ll2 = NULL;
        BSTtoDLL(root2, ll2);
        
        Node *mergedDLL = mergeTwoSortedDLL(ll1, ll2);
        mergedDLL->left = NULL;
        int n = countNodes(mergedDLL);
        
        return DLLtoBST(mergedDLL, n);
        return NULL;
    }
};


Node *mergeBST(Node *root1, Node *root2){
    // Write your code here.
    Approach1 obj1;
    return obj1.findAns(root1, root2);
}