#include<bits/stdc++.h>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
}

void merge(int arr1[], int arr2[], int n, int m) {
    // int i = 0;

    // while(i < n) {
    //     if(arr1[i] > arr2[0]) {
    //         swap(arr1[i],arr2[0]);
    //         if(i != n-1)
    //             swap(arr1[i+1],arr2[0]);
    //         if(arr2[0] > arr2[1]) {
    //             sort(arr2,arr2+m);
    //         }
    //         if(i != n-2)
    //             i++;
    //     } 
    //     i++;
    // }

    int i=n-1, j=0, k=0;
	    
    while(arr1[i] > arr2[j] && j!=m && i>=0) {
        swap(arr1[i],arr2[j]);
        i--;
        j++;
    }
    sort(arr1,arr1+n);
    sort(arr2,arr2+m);

}

int main()
{
    int a[] = {0,2,6,8,9};
    int n = sizeof(a)/sizeof(a[0]);
    int b[] = {1,3,5,7};
    int m = sizeof(b)/sizeof(b[0]);

    merge(a,b,n,m);
    print(a,n);
    print(b,m);
}