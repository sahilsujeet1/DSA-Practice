#include<bits/stdc++.h>
using namespace std;

vector<int> addArrays(vector<int>& a, int n, vector<int>& b, int m) {

    int i = n-1;
    int j = m-1;
    int carry = 0;

    vector<int> ans;

    while (i >= 0 && j >= 0) {
        int sum = a[i] + b[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--; j--;
    }

    while (i >= 0) {
        int sum = a[i] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        i--;
    }
    
    while (j >= 0) {
        int sum = b[j] + carry;
        carry = sum/10;
        sum = sum%10;
        ans.push_back(sum);
        j--;
    }

    reverse(ans.begin(), ans.end());
    return ans;
}

int main()
{
    vector<int> a = {9,2,3,4};
    vector<int> b = {7,2,9};

    vector<int> result = addArrays(a,4,b,3);

    for(auto i:result) {
        cout << i;
    } cout << endl;

}