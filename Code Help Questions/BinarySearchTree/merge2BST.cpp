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


Node *mergeBST(Node *root1, Node *root2){
    // Write your code here.
    Approach1 obj1;
    return obj1.findAns(root1, root2);
}