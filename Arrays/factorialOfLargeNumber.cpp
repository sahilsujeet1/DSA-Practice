#include <bits/stdc++.h>
using namespace std;

vector<int> factorial(int N)
{
    // code here
    int arr[2568];
    int n = 2568;
    arr[n - 1] = 1;
    int res = 1;
    int carry = 0;

    for (int i = 2; i <= N; i++)
    {
        carry = 0;
        for (int j = n - 1; j > n - 1 - res; j--)
        {
            int temp = arr[j] * i + carry;
            arr[j] = temp % 10;
            carry = temp / 10;
        }
        while (carry)
        {
            arr[n - 1 - res] = carry % 10;
            carry /= 10;
            res++;
        }
    }

    vector<int> ans(res, 0);
    int j = 0;
    for (int i = n - res; i < n; i++)
        ans[j++] = arr[i];
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<int> ans = factorial(n);
    
    cout << "\nFactorial: ";
    for(auto x:ans) {
        cout << x;
    } cout << endl;
}