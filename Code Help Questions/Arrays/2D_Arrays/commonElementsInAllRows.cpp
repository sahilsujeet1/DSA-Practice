#include<bits/stdc++.h>
using namespace std;

void printCommonElements(int mat[4][5]) {
    vector<int> ans;

    for(int i=0; i<4; i++) {
        vector<int> arr;
        for(int j=0; j<5; j++) {
            if(find(arr.begin(), arr.end(), mat[i][j]) != arr.end()) {
                arr.push_back(mat[i][j]);
            }
        }
    }
}

int main() {
    int mat[4][5] = {{1, 2, 1, 4, 8},
             {3, 7, 8, 5, 1},
             {8, 7, 7, 3, 1},
             {8, 1, 2, 7, 9},
            };

    printCommonElements(mat);

}