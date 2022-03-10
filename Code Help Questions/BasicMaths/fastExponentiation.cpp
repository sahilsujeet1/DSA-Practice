#include<bits/stdc++.h>
using namespace std;

int getPower(int a, int b) {
    long long int res = 1;

    while(b > 0) {
        if(b&1) {
            res = (res * a);
        }
        a = (a*a);
        b = b>>1;
    }
    return res;
}

int main() {
    int num, p;
    cin >> num >> p;
    cout << getPower(num, p) << endl;
}