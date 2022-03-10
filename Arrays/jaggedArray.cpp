#include<iostream>
using namespace std;

int main() {
    int row;
    cout << "Enter number of rows: ";
    cin >> row;

    int *cols = new int[row];

    int **arr = new int*[row];

    // Creating jagged 2d array
    for(int i=0; i<row; i++) {
        cout << "Enter length of col-" << i+1 << ": ";
        cin >> cols[i];
        arr[i] = new int[cols[i]];
        for(int j=0; j<cols[i]; j++) {
            cin >> arr[i][j];
        }
    }

    // Taking values in the array
    // for(int i=0; i<row; i++) {
    //     for(int j=0; j<cols[i]; j++) {
    //         cin >> arr[i][j];
    //     }
    // }
    // Printing values
    cout << endl;
    for(int i=0; i<row; i++) {
        for(int j=0; j<cols[i]; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }

    // Releasing memory
    for(int i=0; i<row; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}