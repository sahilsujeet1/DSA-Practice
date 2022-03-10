#include <bits/stdc++.h>
using namespace std;

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;

    int row = matrix.size();
    int col = matrix[0].size();
    int total = row * col;
    int count = 0;

    int startR = 0;
    int endR = row - 1;
    int startC = 0;
    int endC = col - 1;

    while (count < total)
    {
        for (int i = startC; count < total && i <= endC; i++)
        {
            ans.push_back(matrix[startR][i]);
            count++;
        }
        startR++;

        for (int i = startR; count < total && i <= endR; i++)
        {
            ans.push_back(matrix[i][endC]);
            count++;
        }
        endC--;

        for (int i = endC; count < total && i >= startC; i--)
        {
            ans.push_back(matrix[endR][i]);
            count++;
        }
        endR--;

        for (int i = endR; count < total && i >= startR; i--)
        {
            ans.push_back(matrix[i][startC]);
            count++;
        }
        startC++;
    }

    return ans;
}

int main()
{
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

    vector<int> spiral = spiralOrder(matrix);

    for(auto x:spiral) {
        cout << x << " ";
    } cout << endl;
}