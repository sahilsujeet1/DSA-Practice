#include <bits/stdc++.h>
using namespace std;

long long int solve(vector<int> &nums) {
    int n = nums.size();

    long long int prev2 = 0;
    long long int prev1 = nums[0];
    
    for(int i=1; i<n; i++) {
        long long int inc = nums[i] + prev2;
        long long int exc = prev1;
        long long int ans = max(inc, exc);
        prev2 = prev1;
        prev1 = ans;
    }
    
    return prev1;
}

long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n = valueInHouse.size();
    if(n == 1) return valueInHouse[0];
    
    vector<int> first, sec;
    for(int i=0; i<n; i++) {
        if(i != n-1)
            first.push_back(valueInHouse[i]);
        if(i != 0)
            sec.push_back(valueInHouse[i]);
    }
    
    return max(solve(first), solve(sec));
}