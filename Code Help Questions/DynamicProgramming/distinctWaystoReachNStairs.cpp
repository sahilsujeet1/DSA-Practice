#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007
int solve(int n, int i, vector<int> &dp) {
    if(i == n)
        return 1;
    
    if(i > n)
        return 0;
    
    if(dp[i] != -1)
        return dp[i];
    
    dp[i] = (solve(n, i+1, dp) + solve(n, i+2, dp)) % MOD;
    return dp[i];
}
