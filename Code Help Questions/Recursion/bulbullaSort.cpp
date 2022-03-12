#include<bits/stdc++.h>
using namespace std;

void bulbullaSort(int arr[], int n) {
    if(n == 0 || n == 1)
        return;
    
    for(int i=0; i<n-1; i++) {
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }

    bulbullaSort(arr, n-1);
}

int main() {
    int arr[] = {8,1,6,-7,25,95,-75};
    int n = sizeof(arr)/sizeof(arr[0]);
    bulbullaSort(arr, n);

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}