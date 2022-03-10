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

int main() {
    int nums[] = {12,18,21,4,7,9,10};
    int n = sizeof(nums)/sizeof(nums[0]);

    cout << "\nPivot element found at index: " << pivot(nums,n) << endl;

}