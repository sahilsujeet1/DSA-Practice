#include<iostream>
using namespace std;

void print(int arr[], int n) {
    for(int i=0; i<n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int getSum(int arr[], int n) {

    if(n == 0)
        return 0;
    if(n == 1)
        return arr[0];
        
    int sum = arr[0] + getSum(arr+1, n-1);
    return sum;
}

int main() {
    int arr[] = {5,7,9,12,39,56};
    int n = sizeof(arr)/sizeof(arr[0]);

    cout << "Sum of array: " << getSum(arr, n) << endl;
}