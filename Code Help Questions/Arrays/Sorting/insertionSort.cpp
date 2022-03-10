// Cards sorting example

// WHY? - Adaptable (Sorts in every round with time), Stable
// Space Complexity - O(1)
// Time Complexity - O(n^2)  Best Case - O(n)  Worst Case - O(n^2 )

#include<iostream>
using namespace std;

// void insertionSort(int arr[], int n) {

//     for(int i=1; i<n; i++) {
//         int temp = arr[i];
//         int j=i-1;
//         for(; j>=0; j--) {
//             if(arr[j] > temp) {
//                 arr[j+1] = arr[j];
//             } else {
//                 break;
//             }
//         }
//         arr[j+1] = temp;
//     }

// }

void insertionSort(int arr[], int n) {
    int i=1;
    while(i < n) {
        int j=i-1;
        int temp = arr[i];
        while(j >= 0) {
            if(arr[j] > temp) {
                arr[j+1] = arr[j];
            } else {
                break;
            }
            j--;
        }
        arr[j+1] = temp;
        i++;
    }
}

int main() {
    int arr[] = {12,58,42,34,6,346};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "\nOriginal Array: ";
    for(auto x:arr) 
        cout << x << " ";
    cout << endl;

    insertionSort(arr, n);

    cout << "\nSorted Array: ";

    for(auto x:arr) 
        cout << x << " ";
    cout << endl;
}