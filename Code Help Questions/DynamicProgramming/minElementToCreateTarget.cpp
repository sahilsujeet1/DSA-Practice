#include <bits/stdc++.h>
using namespace std;

int solveRec(vector<int> &num, int x) {
    if(x == 0) return 0;
    
    if(x < 0) return INT_MAX;
    
    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = solveRec(num, x-num[i]);
        
        if(ans != INT_MAX)
            mini = min(mini, 1+ans);
    }
    return mini;
}

int solveMem(vector<int> &num, int x, vector<int> &dp) {
    if(x == 0) return 0;
    if(x < 0) return INT_MAX;
    
    if(dp[x] != -1)
        return dp[x];
    
    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++) {
        int ans = solveMem(num, x-num[i], dp);
        
        if(ans != INT_MAX)
            mini = min(mini, ans+1);
    }
    
    dp[x] = mini;
    return dp[x];
}