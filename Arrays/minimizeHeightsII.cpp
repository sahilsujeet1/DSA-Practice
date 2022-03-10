#include<bits/stdc++.h>
#include<math.h>
using namespace std;

int minimize(int arr[], int n, int k) {
    int minSum = INT32_MAX, smallest = 0, largest = 0;
    sort(arr,arr+n);
    minSum = arr[n-1]-arr[0];

    for(int i=1; i<n; i++) {
        if(arr[i] >= k) {
            largest = max(arr[n-1]-k,arr[i-1]+k);
            smallest = min(arr[i]-k, arr[0]+k);
            minSum = min(minSum, largest-smallest);
        }
    }
        
    return minSum;
}

int main()
{
    int heights[] = {4,8,6,7,12,2};
    int n = sizeof(heights)/sizeof(heights[0]);
    cout << minimize(heights, n, 3) << endl;
}