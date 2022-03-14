#include <bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int s, int n) {
    if(s > n)
        return;

    int min = s;
    for(int i=s+1; i<n; i++) {
        if(arr[i] < arr[min])
            min = i;
    }
    swap(arr[min], arr[s]);

    selectionSort(arr, s+1, n);

}

int main()
{
    int arr[] = {8, 1, 6, -7, 25, 95, -75};
    int n = sizeof(arr) / sizeof(arr[0]);
    selectionSort(arr, 0, n);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}