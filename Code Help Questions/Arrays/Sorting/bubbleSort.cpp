// Space Complexity: O(1)
// Time Complexity: O(n^2)  Best Case: O(n)  Worst Case: O(n^2)
// Most suitable for small arrays, vectors, lists OR when less memory usage is required

#include<iostream>
using namespace std;

void bubbleSort(int arr[], int n) {

    for(int i=1; i<n; i++) {
        bool swapped = false;
        for(int j=0; j<n-i; j++) {
            if(arr[j] > arr[j+1]) {
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }

        if(swapped == false) break; // already sorted (OPTIMIZATION)
    }

}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,0,1,2,3,4,4,0,4,2,4,34,23,42,34,23,4,234,23,42,3,236,34,0,43,623,46,4,6,34,62,4,64,6,2,46,234,6,3,462,34,63,246,24,6,24,62,4,46,234,6,234,63,46,234,6,346,324,6,234,6,234,6,346};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nOriginal Array: ";
    for(auto x:arr) 
        cout << x << " ";
    cout << endl;

    bubbleSort(arr, n);

    cout << "\nSorted Array: ";

    for(auto x:arr) 
        cout << x << " ";
    cout << endl;
}