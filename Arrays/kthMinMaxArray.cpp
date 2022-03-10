#include<bits/stdc++.h>
using namespace std;

struct minMax {
    int k_min, k_max;
};

struct minMax kthMinMax(int arr[], int n, int k) {
    struct minMax ans;
    sort(arr+0, arr+n);
    ans.k_min = arr[k-1];
    ans.k_max = arr[n-k];
    
    return ans;
}

int main() {
    int a[] = {7,10,4,20,15}; //4,7,10,15,20
    int n = 5, k;

    cout << "Enter k: ";
    cin >> k;
    struct minMax result = kthMinMax(a, n, k);
    cout << k << "th Minimum: " << result.k_min << endl;
    cout << k << "th Maximum: " << result.k_max << endl;
}