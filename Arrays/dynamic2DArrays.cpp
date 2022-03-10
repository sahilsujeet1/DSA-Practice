#include<iostream>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    // Creating rows for 2D Dynamic Array
    int **arr = new int*[n];
    // Creating columns for each row of 2D Array
    for(int i=0; i<m; i++) {
        arr[i] = new int[n];
    }

    // Taking values of 2D Array
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    // Printing values
    cout << endl;
    for(int i=0; i<m; i++) {
        for(int j=0; j<n; j++) {
            cout << arr[i][j] << " ";
        } cout << endl;
    }

    // Releasing memory
    for(int i=0; i<m; i++) {
        delete [] arr[i];
    }
    delete [] arr;
}