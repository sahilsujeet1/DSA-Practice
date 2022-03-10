#include<bits/stdc++.h>
using namespace std;

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

void rotate(int arr[], int n, int k) {
    int temp[n];

    for(int i=0; i<n; i++) {
        temp[(i+k)%n] = arr[i];
    }
    
    cout << "Array after rotation: ";
    printArray(temp, n);
}

int main()
{
    int nums[] = {4,9,12,65,74,91};
    int n = sizeof(nums)/sizeof(nums[0]);
    int k;
    cout << "Enter steps to rotate: ";
    cin >> k;

    cout << "Original Array: ";
    printArray(nums, n);

    rotate(nums, n, k);
}