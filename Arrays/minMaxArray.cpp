#include<bits/stdc++.h>
using namespace std;

void minMaxLinearSearch(int arr[], int size) {
    int min=INT32_MAX, max=INT32_MIN;

    for(int i=0; i<size; i++) {
        if(arr[i] <= min) {
            min = arr[i];
        }

        if(arr[i] >= max) {
            max = arr[i];
        }
    }

    cout << "Minimum in array: " << min << endl;
    cout << "Maximum in array: " << max << endl;
}

struct minMax {
    int min, max;
};

struct minMax find(int arr[], int start, int end) {
    struct minMax minmax, mml, mmr;

    if(start == end) {
        minmax.min = arr[start];
        minmax.max = arr[end];

        return minmax;
    }

    if(start == end-1) {
        if(arr[start] < arr[end]) {
            minmax.min = arr[start];
            minmax.max = arr[end];
        } else {
            minmax.min = arr[end];
            minmax.max = arr[start];
        }

        return minmax;
    }

    int mid = (start+end)/2;
    mml = find(arr, start, mid);
    mmr = find(arr, mid+1, end);

    if(mml.min < mmr.min) {
        minmax.min = mml.min;
    } else {
        minmax.min = mmr.min;
    }
    if(mml.max > mmr.max) {
        minmax.max = mml.max;
    } else {        
        minmax.max = mmr.max;
    }

    return minmax;
}

int main()
{
    int a[] = {45,1,-56,92,518,0};
    int n = sizeof(a)/sizeof(a[0]);

    cout << "\nUsing Linear Search:- \n";
    minMaxLinearSearch(a, n);

    cout << "\nUsing recursion:- \n";
    struct minMax minmax = find(a, 0, n-1);
    cout << "Minimum: " << minmax.min << endl;
    cout << "Maximum: " << minmax.max << endl;
}