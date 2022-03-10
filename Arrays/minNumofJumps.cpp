#include<bits/stdc++.h>
using namespace std;

int jumps(int arr[], int n) {
    // int count = 0, i = 0, sum = 0;
    // if(i == 0) count = 0;
    // while(i<n) {
    //     sum = sum+arr[i];
    //     if(arr[i] == 0) break;
    //     if(arr[i+arr[i]] < arr[i+arr[i]-1]) {
    //         i = i+arr[i]-1;
    //     } else {
    //         i = i+arr[i];
    //     }
            
    //     count++;
    //     if(sum >= n) break;
    // }

    // if(sum < n) return -1;
    // return count;

    if(n <= 1) return 0;
    if(arr[0] == 0) return -1;

    int steps=arr[0], maxreach=arr[0], jump=1;

    for(int i=1; i<n; i++) {
        if(i == n-1) return jump;

        maxreach = max(maxreach, i+arr[i]);
        steps--;

        if(steps == 0) {
            jump++;
            if(i >= maxreach) return -1;
            steps = maxreach - i;
        }
    }
    return -1;
}

int main()
{
    int arr[] = {1,3,5,8,9,2,6,7,6,8,9};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout << jumps(arr, n) << endl;

}