#include<iostream>
using namespace std;

void reverseWholeArray(int arr[], int n) {
    int j=n-1;

    for(int i=0; i<n/2; i++) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        j--;
    }
}

void reverseSpecificPositions(int arr[], int start, int end) {
    start--; end--;
    while(start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void printArray(int arr[], int n) {
    for(int i=0; i<n; i++) {
        cout << arr[i] << " ";
    } cout << endl;
}

int main()
{
    int arr[] = {8,1,6,7,3,4,2,0,78,23,9,15,34,-4,0,46,-995,52};
    int n = sizeof(arr)/sizeof(arr[0]);

    reverseWholeArray(arr, n);
    printArray(arr, n);

    int s,e;
    cout << "\nEnter starting and position of array to reverse elements: ";
    cin >> s >> e;
    reverseSpecificPositions(arr, s, e);
    printArray(arr, n);
}
