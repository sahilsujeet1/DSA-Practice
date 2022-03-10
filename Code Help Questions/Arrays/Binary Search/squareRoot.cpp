#include<iostream>
#define ll long long
using namespace std;

double precision(ll int n, int p, int tempSol) {

    double factor = 1;
    double ans = tempSol;

    for(int i=0; i<p; i++) {
        factor /= 10;
        for(double j=ans; j*j<n; j+=factor) {
            ans = j;
        }
    }
    return ans;
}

double findRoot(ll int n, int p) {
    ll int s =0 , e = n, mid = s + (e-s)/2;
    ll int space[n];
    int ans = -1;

    for(ll int i=0; i<n; i++) {
        space[i] = i;
    }

    while(s <= e) {
        
        if(space[mid] * space[mid] > n) {
            e = mid-1;
        } else {
            ans = space[mid];
            s = mid + 1;
        }

        mid = s + (e-s)/2;
    }

    return precision(n, p, ans);
}

int main()
{
    ll int n, p;
    cout << "Enter a number and decimal precision to find its root: ";
    cin >> n >> p;
    cout << "Root is: " << findRoot(n,p) << endl;
}