#include<iostream>
using namespace std;

int binarySearch(int arr[], int n, int k) {
    int s = 0, e = n-1, mid = s + (e-s)/2;

    while(s <= e) {
        if(arr[mid] == k) return mid;
        if(arr[mid] < k) s = mid+1;
        else e = mid-1;
        mid = s + (e-s)/2;
    }
    return -1;
}

int main() {
    int nums[] = {4,9,12,65,74,91}, target;
    int n = sizeof(nums)/sizeof(nums[0]);
    cout << "Enter target element: ";
    cin >> target;

    cout << "\nTarget element found at index: " << binarySearch(nums,n,target) << endl;

}