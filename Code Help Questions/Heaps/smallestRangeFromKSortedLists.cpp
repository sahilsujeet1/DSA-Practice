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

int kSorted(vector<vector<int>> &a, int k, int n) {
    // Write your code here.
    priority_queue<node*, vector<node*>, compare> minHeap;
    int mini = INT_MAX, maxi = INT_MIN;
    
    for(int i=0; i<k; i++) {
        node* temp = new node(a[i][0], i, 0);
        minHeap.push(temp);
        maxi = max(maxi, temp->data);
        mini = min(mini, temp->data);
    }
    
    int start = mini, end = maxi;
    
    while(!minHeap.empty()) {
        node *temp = minHeap.top();
        minHeap.pop();
        
        mini = temp->data;
        
        if(maxi-mini < end-start) {
            start = mini;
            end = maxi;
        }
        
        if(temp->col+1 < n) {
            maxi = max(maxi, a[temp->row][temp->col+1]);
            minHeap.push(new node(a[temp->row][temp->col+1], temp->row, temp->col+1));
        } else {
            break;
        }
    }
    
    return end-start+1;
}