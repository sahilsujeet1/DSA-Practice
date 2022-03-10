#include<bits/stdc++.h>
using namespace std;

int duplicate(vector<int>& nums) {
    int num;
    sort(nums.begin(), nums.end());
    for(int i=0; i<nums.size(); i++) {
        if(nums[i+1] == nums[i]) {
            num = nums[i];
            break;
        }
    }
    return num;
}


int findDuplicate(vector<int>& nums) {
    for(int i=0; i<nums.size(); i++) {
        if(nums[0] != nums[nums[0]]) {
            swap(nums[0], nums[nums[0]]);
        } else {
            return nums[0];
        }
    }
    return -1;
}

int main()
{
    vector<int> nums = {1,3,4,2,2};
    cout << findDuplicate(nums) << endl;
}