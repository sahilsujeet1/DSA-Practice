#include<bits/stdc++.h>
#include "node.cpp"

void inorder(Node* root, vector<int> &in) {
    if(root == NULL)
        return;
    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(Node* root, int target) {
	//Write your code here
    vector<int> in;
    inorder(root, in);
    int n = in.size();
    int i = 0, j = n-1;
    
    while(i < j) {
        int sum = in[i] + in[j];
        
        if(sum == target)
            return true;
        else if(sum > target)
            j--;
        else
            i++;
    }
    return false;
}