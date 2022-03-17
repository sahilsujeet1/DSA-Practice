#include<bits/stdc++.h>
using namespace std;

void solve(string digits, string output, int index, vector<string>& ans, string mapping[]) {
    if(index >= digits.length()) {
        ans.push_back(output);
        return;
    }
    
    int number = digits[index] - '0';
    string value = mapping[number];
    
    for(int i=0; i<value.length(); i++) {
        output.push_back(value[i]);
        solve(digits, output, index+1, ans, mapping);
        output.pop_back();
    }
}

vector<string> letterCombination(string digits) {
    vector<string> ans;
        
    if(digits.length() == 0)
        return ans;
    
    int index = 0;
    string mapping[10] = {"", "", "abc","def","ghi","jkl", "mno", "pqrs", "tuv", "wxyz"};
    string output = "";
    
    solve(digits, output, index, ans, mapping);
    return ans;
}

int main() {

    string input = "274";
    vector<string> ans = letterCombination(input);

    cout << endl << "Output: " << endl;
    for(auto x:ans) {
        for(auto y: x) {
            cout << y;
        } cout << endl;
    } cout << endl;

}