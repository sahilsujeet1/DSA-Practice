#include<iostream>
using namespace std;

void print(int arr[], int s, int e) {
    for(int i=s; i<=e; i++)
        cout << arr[i] << " ";
    cout << endl;
}

bool binarySearch(int arr[], int s, int e, int k) {

    // print(arr, s, e);

    if(s>e)
        return false;
    
    int mid = s + (e-s)/2;
    // cout << "arr[mid] = " << arr[mid] << endl;

    if(arr[mid] == k)
        return true;
    else if(arr[mid] < k)
        return binarySearch(arr, mid+1, e, k);
    else
        return binarySearch(arr, s, mid-1, k);
}


int main() {
    int arr[] = {5,7,9,12,39,56,60,69,75,81,99,102};
    int n = sizeof(arr)/sizeof(arr[0]);
    int k;
    cin >> k;

    cout << "Element found: " << binarySearch(arr, 0, n-1, k) << endl;
}