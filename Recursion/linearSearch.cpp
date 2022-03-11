#include<iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool linearSearch(int arr[], int n, int k) {
    // print(arr, n);
    if(n == 0)
        return false;
    if(arr[0] == k)
        return true;
    return linearSearch(arr+1, n-1, k);
}


int main() {
    int arr[] = {5,7,9,12,39,56};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;

    cout << "Element found: " << linearSearch(arr, n, k) << endl;
}