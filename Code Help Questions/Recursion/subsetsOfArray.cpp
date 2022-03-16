#include<bits/stdc++.h>
using namespace std;

void subsets(vector<int> arr, vector<int> output, int i, vector<vector<int>>& ans) {
    if(i >= arr.size()) {
        ans.push_back(output);
        return;
    }

    // Exclude
    subsets(arr, output, i+1, ans);

    // Include
    output.push_back(arr[i]);
    subsets(arr, output, i+1, ans);
}

int main() {
    vector<int> arr = {1,2,3,4};

    vector<vector<int>> ans;
    vector<int> output;

    subsets(arr, output, 0, ans);    

    cout << endl << "Output: " << endl;
    for(auto x:ans) {
        for(auto y: x) {
            cout << y << " ";
        } cout << endl;
    } cout << endl;

}