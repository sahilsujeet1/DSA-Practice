#include<bits/stdc++.h>
using namespace std;

int leftMost(int arr[], int n, int k) {
    int s = 0, e = n-1, mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(arr[mid] == k) {
            ans = mid;
            e = mid-1;
        } else if (arr[mid] < k) {
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

int rightMost(int arr[], int n, int k) {
    int s = 0, e = n-1, mid = s + (e-s)/2;
    int ans = -1;
    while(s <= e) {
        if(arr[mid] == k) {
            ans = mid;
            s = mid+1;
        } else if (arr[mid] < k) {
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }
    return ans;
}

pair<int,int> getOccurrence(int arr[], int n, int k) {
    pair<int,int> result;
    result.first = leftMost(arr,n,k);
    result.second = rightMost(arr,n,k);
    return result;
}

int main()
{
    int nums[] = {4,9,9,9,9,12,65,74,91}, target;
    int n = sizeof(nums)/sizeof(nums[0]);
    pair<int,int> foundAt;
    cout << "Enter target element: ";
    cin >> target;

    foundAt = getOccurrence(nums,n,target);

    if(foundAt.first != -1 && foundAt.second != -1) {
        cout << "First occurrence of target element is at index: " << foundAt.first << endl;
        cout << "Last occurrence of target element is at index: " << foundAt.second << endl;
        cout << "Total number of occurrences of target element: " << foundAt.second - foundAt.first + 1 << endl;
    } else {
        cout << "Target element not found!" << endl;
    }
    
}