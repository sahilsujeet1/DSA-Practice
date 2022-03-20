#include<bits/stdc++.h>
using namespace std;

void nextPermutation(vector<int> &nums) {
    int n = nums.size();
    int i = n-2;

    while(i >= 0 && nums[i] >= nums[i+1]) {
        i--;
    }

    if(i >= 0) {
        int j = n-1;
        while(nums[j] <= nums[i]) {
            j--;
        }
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin()+i+1, nums.end());
}

int main() {
    vector<int> nums = {1,1,5};
    nextPermutation(nums);
    cout << "\nNext Permutation: " << endl;
    for(auto x: nums) {
        cout << x << " ";
    } cout << endl;
}