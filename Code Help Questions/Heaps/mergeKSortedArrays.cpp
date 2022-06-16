#include <bits/stdc++.h>
using namespace std;

class node {
    public:
    int data, row, col;
    
    node(int d, int i, int j) {
        data = d;
        row = i;
        col = j;
    }
};

class compare {
    public:
    bool operator()(node* a, node* b) {
        return a->data > b->data;
    }
};

vector<int> mergeKSortedArrays(vector<vector<int>>&kArrays, int k)
{
    // Write your code here. 
    priority_queue<node*, vector<node*>, compare > minHeap;
    
    for(int i=0; i<k; i++) {
        node *temp = new node(kArrays[i][0], i, 0);
        minHeap.push(temp);
    }
    
    vector<int> ans;
    
    while(!minHeap.empty()) {
        node *top = minHeap.top();
        minHeap.pop();
        int i = top->row;
        int j = top->col;
        int d = top->data;
        
        ans.push_back(d);
        
        if(j+1 < kArrays[i].size()) {
            node *temp = new node(kArrays[i][j+1], i, j+1);
            minHeap.push(temp);
        }
    }
    
    return ans;
}
