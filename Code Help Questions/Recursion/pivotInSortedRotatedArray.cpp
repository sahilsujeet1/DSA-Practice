#include<bits/stdc++.h>
using namespace std;

int pivotIndex(vector<int> arr, int s, int e) {
    int mid = s + (e-s)/2;
    if(s < e)
        return mid;

    if(arr[mid] >= arr[0])
        return pivotIndex(arr, mid+1, e);
    else   
        return pivotIndex(arr, s, mid);

}

int main() {
    vector<int> arr = {1,7,3,6,5,6};
    int n = arr.size();
    cout << pivotIndex(arr, 0 ,n) << endl;

    return 0;
}