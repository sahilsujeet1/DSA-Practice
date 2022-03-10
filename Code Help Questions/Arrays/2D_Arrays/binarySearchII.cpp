#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int rowIndex = 0;
    int colIndex = col-1;
    
    while(rowIndex < row && colIndex >= 0) {
        int element = matrix[rowIndex][colIndex];

        if(element == target)
            return 1;
        if(element < target) {
            rowIndex++;
        } else {
            colIndex--;
        }
    }

    return 0;
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

    int t;
    cin >> t;

    cout << binarySearch(matrix,t) << endl;
}