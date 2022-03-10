#include<bits/stdc++.h>
using namespace std;

void rotate(vector<vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose of the matrix
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse of each row
    for(int i=0; i<n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
    }


    // Optimised Solution

    // int l = matrix.size()-1; // end index
        
    // for(int r=0; r<(l+1)/2; r++)  // travering only half of matrix
    //     for(int c=r; c< l-r; c++){  // reducing the inner window
    //         int temp = matrix[l-c][r];
    //         matrix[l-c][r] = matrix[l-r][l-c];
    //         matrix[l-r][l-c] = matrix[c][l-r];
    //         matrix[c][l-r] = matrix[r][c];
    //         matrix[r][c] = temp;
    //     }
}

int main() {
    vector<vector<int>> matrix;
    int row, col;
    cin >> row >> col;

    for (int i = 0; i < row; i++)
    {
        vector<int> cols;
        for (int j = 0; j < col; j++)
        {
            int x;
            cin >> x;
            cols.push_back(x);
        }
        matrix.push_back(cols);
    }

    rotate(matrix);
    // Printing output matrix
    for(int i=0; i<row; i++) {
        for(int j=0; j<col; j++) {
            cout << matrix[i][j] << " ";
        } cout << endl;
    } cout << endl;
}