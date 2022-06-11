#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    
    void heapify(vector<int> &arr, int i) {
        int largest = i;
        int left = 2*i+1;
        int right = 2*i+2;
        int n = arr.size();
        
        if(left < n && arr[left] > arr[largest])
            largest = left;
            
        if(right < n && arr[right] > arr[largest])
            largest = right;
            
        if(largest != i) {
            swap(arr[largest], arr[i]);
            heapify(arr, largest);
        }
    }
    
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        // your code here
        vector<int> mergedArr;
        
        for(auto x:a)
            mergedArr.push_back(x);
            
        for(auto x:b)
            mergedArr.push_back(x);
            
        for(int i=mergedArr.size()/2-1; i>=0; i--) {
            heapify(mergedArr, i);
        }
        return mergedArr;
    }
};