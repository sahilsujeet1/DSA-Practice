#include <bits/stdc++.h>
using namespace std;

class Heap {
    public:
    int arr[100];
    int size;

    Heap() {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val) {
        size = size+1;
        int i = size;
        arr[i] = val;

        while(i > 1) {
            int parent = i/2;

            if(arr[parent] < arr[i]) {
                swap(arr[parent], arr[i]);
                i = parent;
            } else {
                return;
            }
        }
    }

    void print() {
        for(int i=1; i<=size; i++) {
            cout << arr[i] << " ";
        } cout << endl;
    }

    void deleteFromHeap() {

        if(size == 0) {
            cout << "Nothing to delete" << endl;
            return;
        }

        // step1: put last element at first index
        arr[1] = arr[size-1];
        // step2: remove last element
        size--;
        // step3: take root node to its correct position
        int i=1;
        while(i < size) {
            int leftIndex = 2*i;
            int rightIndex = 2*i+1;

            if(leftIndex < size && arr[i] < arr[leftIndex]) {
                swap(arr[i], arr[leftIndex]);
            } else if(rightIndex < size && arr[i] < arr[rightIndex]) {
                swap(arr[i], arr[rightIndex]);
            } else {
                return;
            }
        }
    }

};

void heapify(int arr[], int n, int i) { // Time Complexity = O(n)     max heap
    int largest = i;
    int left = 2*i;
    int right = 2*i + 1;

    if(left < n && arr[largest] < arr[left])
        largest = left;
    
    if(right < n && arr[largest] < arr[right])
        largest = right;

    if(largest != i) {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

int main() {
    Heap h;
    h.insert(20);
    h.insert(10);
    h.insert(11);
    h.insert(54);
    h.insert(61);
    h.insert(7);
    h.print();

    h.deleteFromHeap();
    h.print();

    // Heapify algorithm example
    int arr[6] = {-1, 32,53,12,64,25};
    int n = 5;
    for(int i=n/2; i>0; i--) {
        heapify(arr, n, i);
    }

    for(int i=1; i<=n ;i++) {
        cout << arr[i] << " ";
    } cout << endl;
}