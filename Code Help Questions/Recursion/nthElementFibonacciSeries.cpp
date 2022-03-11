#include<iostream>
#include <chrono>   
using namespace std;
using namespace std::chrono;
#define ll long long 

ll int rfibonacci(int n) {
    ll int ans = 0;
    if(n == 0) {
        return 0;
    }
    if(n == 1) {
        return 1;
    }

    return rfibonacci(n-1) + rfibonacci(n-2);
}

ll int ifibonacci(int n) {
    ll int a = 0, b = 1, c;
    for(int i=2; i<=n; i++) {
        c = a+b;
        a = b;
        b = c;
    }

    return c;
}

int main() {
    

    int n;
    cin >> n;
    cout << endl;
    
    auto start = high_resolution_clock::now();
    // cout << n << "th element starting from 0 of fibonacci series is " << rfibonacci(n) << endl;
    cout << n << "th element starting from 0 of fibonacci series is " << ifibonacci(n) << endl;

    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << endl << "Program took : " << duration.count() << " microseconds" << endl;
  
}