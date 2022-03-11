#include<iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool isSorted(int arr[], int n) {
    // print(arr, n);
    if(n == 0 || n == 1)
        return true;
    if(arr[0] > arr[1])
        return false;
    return isSorted(arr+1, n-1);
}

int main() {
    // int arr[] = {5,7,9,12,42,39,56};
    int arr[] = {5,7,9,12,39,56};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Is array sorted: " << isSorted(arr, n) << endl;
}