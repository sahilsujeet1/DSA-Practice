#include<bits/stdc++.h>
using namespace std;

int maxArea(vector<vector<int>> mat, int n, int m) {
    
    int maxi = -1;
    int count = 0;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m ;j++) {
            if(mat[i][j] == 1) {
                count++;
                if(count > maxi) maxi = count;
            }
        }
    }
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

    cout << maxArea(matrix,row,col);
}