#include <bits/stdc++.h>
using namespace std;

void heapify(int arr[], int n, int i) { // Time Complexity = O(n)     max heap
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left <= n && arr[largest] < arr[left])
        largest = left;
    
    if(right <= n && arr[largest] < arr[right])
        largest = right;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,4,0,4,2,4,34,23,42,34,23,4,234,23,42,3,236,34,0,43,623,46,4,6,34,62,4,64,6,2,46,234,6,3,462,34,63,246,24,6,24,62,4,46,234,6,234,63,46,234,6,346,324,6,234,6,234,6,346};
    int n = sizeof(arr)/sizeof(arr[0])-1;
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    heapSort(arr, n);
    cout << "Sorted array: ";
    for(int i=1; i<=n; i++) {
        cout << arr[i] << " ";
    } cout << endl;

    cout << "\n*********PRIORITY QUEUE***************\n";
    priority_queue<int> maxHeap;
    maxHeap.push(3);
    maxHeap.push(2);
    maxHeap.push(5);
    maxHeap.push(1);

    cout << "Max heap top: " << maxHeap.top() << endl;
    maxHeap.pop();
    cout << "Max heap top: " << maxHeap.top() << endl;


    priority_queue<int, vector<int>, greater<int>> minHeap;
    minHeap.push(3);
    minHeap.push(2);
    minHeap.push(5);
    minHeap.push(1);

    cout << "Min heap top: " << minHeap.top() << endl;
    minHeap.pop();
    cout << "Min heap top: " << minHeap.top() << endl;

}