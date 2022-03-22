#include <bits/stdc++.h>
using namespace std;

int merge(int arr[], int s, int e) {
    int count = 0;
    int mid = s+(e-s)/2;

    int len1 = mid-s+1;
    int len2 = e-mid;

    // create two sub arrays from main array separating at mid
    int *left = new int[len1];
    int *right = new int[len2];

    // Copy values in left subarray
    int arrayIndex = s;
    for(int i=0; i<len1; i++) {
        left[i] = arr[arrayIndex++];
    }
    // Copy values in right subarray
    arrayIndex = mid+1;
    for(int i=0; i<len2; i++) {
        right[i] = arr[arrayIndex++];
    }

    // Merge left and right subarrays
    arrayIndex = s;
    int index1 = 0, index2 = 0;

    while(index1 < len1 && index2 < len2) {
        if(left[index1] < right[index2]) {
            arr[arrayIndex++] = left[index1++];
        } else {
            arr[arrayIndex++] = right[index2++];
            count += len1-index1;
        }
    }

    while(index1 < len1)
        arr[arrayIndex++] = left[index1++];

    while(index2 < len2) 
        arr[arrayIndex++] = right[index2++];
    
    delete [] left;
    delete [] right;


    return count;
}

int mergeSort(int arr[], int s, int e) {
    int count = 0;
    if(e > s) {
        int mid = s+(e-s)/2;
        
        count += mergeSort(arr, s, mid);

        count += mergeSort(arr, mid+1, e);

        count += merge(arr, s, e);
    }
        
    return count;

}

int main()
{
    int arr[] = {2,4,1,3,5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << mergeSort(arr, 0, n-1);

    // cout << "Sorted Array: ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    cout << endl;
}