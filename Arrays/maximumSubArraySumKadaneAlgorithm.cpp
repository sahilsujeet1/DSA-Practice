// Kadane's Algorithm
#include<bits/stdc++.h>
using namespace std;

int maaximumSubarraySum(int a[], int n) {
    int max = 0, curr = 0;
    

    for(int i=0; i<n; i++) {
        curr += a[i];
        if(curr > max)
            max = curr;
        if(curr < 0)
            curr = 0;
    }

    return max;
}

int main() 
{
    int a[] = {5,1,6,-4,0,9}; //9 6 5 1 0 -4
    int n = sizeof(a)/sizeof(a[0]);

    cout << maaximumSubarraySum(a,n) << endl;
    
}