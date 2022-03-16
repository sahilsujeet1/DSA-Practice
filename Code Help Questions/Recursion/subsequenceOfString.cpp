#include<bits/stdc++.h>
using namespace std;

void subsets(string str, string output, int i, vector<string>& ans) {
    if(i >= str.length()) {
        if(output.length() > 0)
            ans.push_back(output);
        return;
    }

    // Exclude
    subsets(str, output, i+1, ans);

    // Include
    output.push_back(str[i]);
    subsets(str, output, i+1, ans);
}

int main() {
    string input = "Sahil";

    vector<string> ans;
    string output;

    subsets(input, output, 0, ans);    

    cout << endl << "Output: " << endl;
    for(auto x:ans) {
        for(auto y: x) {
            cout << y;
        } cout << endl;
    } cout << endl;

}