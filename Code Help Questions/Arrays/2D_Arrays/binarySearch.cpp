#include<bits/stdc++.h>
using namespace std;

bool binarySearch(vector<vector<int>>& matrix, int target) {
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0, e = (row*col)-1;
    int mid = s + (e-s)/2;

    while(s <= e) {
        int element = matrix[mid/col][mid%col];
        if(element == target)
            return true;
        if(element < target)
            s = mid+1;
        else   
            e = mid-1;
        mid = s + (e-s)/2;
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

    cout << "Element found: " << binarySearch(matrix,t) << endl;
}