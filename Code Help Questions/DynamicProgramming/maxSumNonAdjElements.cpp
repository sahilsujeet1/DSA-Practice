#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &nums, int n) {
    if(n < 0) return 0;
    if(n == 0) return nums[0];
    
    int inc = nums[n] + solveRec(nums, n-2);
    int exc = solveRec(nums, n-1);
    
    return max(inc, exc);
}