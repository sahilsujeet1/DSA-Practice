#include<bits/stdc++.h>
using namespace std;

int getSum(vector<int>& arr, int i, int n) {
    int sum = 0;

    while (i < n) {
        sum += arr[i];
        i++;
    }
    return sum;
}

int pivotIndex(vector<int>& nums) {
    int n = nums.size();

    for(int i=1; i<n; i++) {
        if(nums[0] == getSum(nums, i, n)) return 0;

        if(getSum(nums,0,i) == getSum(nums, i+1, n)) return i;
    }

    return -1;
}

int main()
{
    vector<int> arr = {1,7,3,6,5,6};
    cout << pivotIndex(arr) << endl;

    return 0;
}