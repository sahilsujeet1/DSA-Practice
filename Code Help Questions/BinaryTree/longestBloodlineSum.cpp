#include <bits/stdc++.h>
#include "node.cpp"
using namespace std;

class Solution
{
public:
    
    void solve(Node *root, int sum, int &maxSum, int len, int &maxLen) {
        if(root == NULL) {
            if(len > maxLen) {
                maxLen = len;
                maxSum = sum;
            } else if(len == maxLen) {
                maxSum = max(sum, maxSum);
            }
            return;
        }
        
        sum = sum + root->data;
        
        solve(root->left, sum, maxSum, len+1, maxLen);
        solve(root->right, sum, maxSum, len+1, maxLen);
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        int maxSum = 0, maxLen = 0, sum = 0, len = 0;
        
        solve(root, sum, maxSum, len, maxLen);
        return maxSum;
        
    }
};
