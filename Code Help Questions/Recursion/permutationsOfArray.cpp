#include<bits/stdc++.h>
using namespace std;

void solve(vector<int> nums, int index, vector<vector<int>>& ans) {
    if(index >= nums.size()) {
        ans.push_back(nums);
    }
    
    for(int j=index; j<nums.size(); j++) {
        swap(nums[j], nums[index]);
        solve(nums, index+1, ans);
        swap(nums[j], nums[index]);
    }
}

vector<vector<int>> permutation(vector<int>& nums) {
    vector<vector<int>> ans;
        
    solve(nums, 0, ans);
    return ans;
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> perm = permutation(arr);

    cout << endl << "Output Permutations: " << endl;
    for(auto x:perm) {
        for(auto y: x) {
            cout << y << " ";
        } cout << endl;
    } cout << endl;
}