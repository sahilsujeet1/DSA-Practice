#include<bits/stdc++.h>
using namespace std;
#define MOD 1e9+5;

long long getPower(int a, int b) {
    if(b == 0)
        return 1;
    if(b == 1)
        return a;

    long long ans = getPower(a, b/2);

    if(b&1) // b is odd
        return a * ans * ans;
    else // b is even
        return ans * ans;
}

int main() {
    int a, b;
    cin >> a >> b;

    cout << getPower(a,b) << endl;
}