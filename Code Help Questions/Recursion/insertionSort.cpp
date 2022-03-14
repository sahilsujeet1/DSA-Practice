#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int s, int n) {
    if(s > n)
        return;

    int i=s-1;
    int temp = arr[s];
    while(i >= 0) {
        if(arr[i] > temp) {
            arr[i+1] = arr[i];
        } else {
            break;
        }
        i--;
    }
    arr[i+1] = temp;
    insertionSort(arr, s+1, n);

}

int main()
{
    int arr[] = {8, 1, 6, -7, 25, 95, -75};
    int n = sizeof(arr) / sizeof(arr[0]);
    insertionSort(arr, 1, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}