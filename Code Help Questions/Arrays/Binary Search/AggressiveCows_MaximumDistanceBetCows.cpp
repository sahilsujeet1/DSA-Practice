#include<bits/stdc++.h>
using namespace std;

bool isPossible(int stalls[], int n, int k, int mid) {
    int cowCount = 1;
    int lastPos = stalls[0];

    for(int i=0; i<n; i++) {
        if(stalls[i]-lastPos >= mid) {
            cowCount++;
            if(cowCount == k)
                return true;
            lastPos = stalls[i];
        }
    }

    return false;
}

int largestMinimumDistance(int stalls[], int n, int k) {
    int maxi=-1, s=0, ans;
    sort(stalls, stalls+n);

    for(int i=0; i<n; i++) maxi = max(maxi, stalls[i]);
    int e = maxi;
    int mid = s + (e-s)/2;

    while(s<=e) {
        if(isPossible(stalls, n, k, mid)) {
            ans = mid;
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }

    return ans;
}

int main()
{
    int positions[] = {10,6,7,12,19};
    int n = sizeof(positions)/sizeof(positions[0]);
    int cows = 2;

    cout << "Largest minimum distance between any two cows: "
    << largestMinimumDistance(positions,n,cows) << endl;
}