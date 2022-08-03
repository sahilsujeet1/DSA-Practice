#include <bits/stdc++.h>
using namespace std;

int solve1(vector<int> &cost, int n) {
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    int ans = cost[n] + min(solve1(cost, n-1), solve1(cost, n-2));
    return ans;
}

int solve2(vector<int> &cost, int n, vector<int> &dp) {
    if(n == 0) return cost[0];
    if(n == 1) return cost[1];

    if(dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] + min(solve1(cost, n-1, dp), solve1(cost, n-2, dp));
    return dp[n];
}