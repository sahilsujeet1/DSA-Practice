#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int n) {
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    
    int inc = nums[n] + solveRec(nums, n-2);
    int exc = solveRec(nums, n-1);
    
    return max(inc, exc);
}

int solveMem(vector<int> &nums, int n, vector<int> &dp) {
    if(n < 0) return 0;
    if(n == 0) return nums[n];
    
    if(dp[n] != -1)
        return dp[n];
    
    int inc = nums[n] + solveMem(nums, n-2, dp);
    int exc = solveMem(nums, n-1, dp);
    
    dp[n] = max(inc, exc);
    return dp[n];
}

int solveTab(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n);
    
    dp[0] = nums[0];
    
    for(int i=1; i<n; i++) {
        int inc = nums[i] + dp[i-2];
        int exc = dp[i-1];
        dp[i] = max(inc, exc);
    }
    
    return dp[n-1];
}

int solveSO(vector<int> &nums) {
    int n = nums.size();
    
    int prev2 = 0;
    int prev1 = nums[0];
    
    for(int i=1; i<n; i++) {
        int inc = nums[i] + prev2;
        int exc = prev1;
        int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.
    int n = nums.size();
    vector<int> dp(n, -1);
//     return solveRec(nums, n-1);
//     return solveMem(nums, n-1, dp);
//     return solveTab(nums);
    return solveSO(nums);
}