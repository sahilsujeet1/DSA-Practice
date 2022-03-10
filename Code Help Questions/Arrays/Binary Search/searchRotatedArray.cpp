#include<iostream>
using namespace std;

int pivot(int arr[], int n) {
    int s = 0, e = n-1, mid = s + (e-s)/2;

    while(s < e) {
        if(arr[mid] >= arr[0]) {
            s = mid+1;
        } else  {
            e = mid;
        }

        mid = s + (e-s)/2;
    }
    return s;
}

int binarySearch(int arr[], int s, int e, int k) {
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == k) return mid;
        if(arr[mid] < k) s = mid+1;
        else e = mid-1;
        mid = s + (e-s)/2;
    }
    return -1;
}

int findPosition(int arr[], int n, int k) {
    int piv = pivot(arr,n);

    if(arr[0] <= k && k < arr[piv]) {
        return binarySearch(arr, 0, piv-1, k);
    } else {
        return binarySearch(arr, piv, arr[n-1], k);
    }
}

int main() {
    int nums[] = {12,18,21,4,7,9,10}, target;
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Enter target element: ";
    cin >> target;

    cout << "\nTarget element found at index: " << findPosition(nums,n,target) << endl;
    return 0;
}