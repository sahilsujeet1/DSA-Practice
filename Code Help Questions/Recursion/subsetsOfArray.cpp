#include<bits/stdc++.h>
using namespace std;

void subsetsRecursion(vector<int> arr, vector<int> output, int i, vector<vector<int>>& ans) {
    if(i >= arr.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude
    subsetsRecursion(arr, output, i+1, ans);

    // Include
    output.push_back(arr[i]);
    subsetsRecursion(arr, output, i+1, ans);
}

vector<vector<int>> subsetsBitMasking(vector<int>& nums) {
        int size = nums.size();
        int subsetSize = (1 << size);
        vector<vector<int>> ans;
        
        for(int subset = 0; subset < subsetSize; subset++) {
            vector<int> subs;
            for(int i = 0; i < size; i++) {
                if((subset & (1 << i)) != 0) {
                    subs.push_back(nums[i]);
                }
            }
            ans.push_back(subs);
        }
        
        return ans;
    }

int main() {
    vector<int> arr = {1,2,3,4};

    vector<vector<int>> ans;
    vector<int> output;

    // subsetsRecursion(arr, output, 0, ans);    
    ans = subsetsBitMasking(arr);
    cout << endl << "Output: " << endl;
    for(auto x:ans) {
        for(auto y: x) {
            cout << y << " ";
        } cout << endl;
    } cout << endl;

}