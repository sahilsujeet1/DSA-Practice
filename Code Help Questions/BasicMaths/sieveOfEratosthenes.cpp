#include<bits/stdc++.h>
using namespace std;


// TIME LIMIT EXCEEDED

// bool isPrime(int n) {
//     if(n<=1) return false;

//     for(int i=2; i<n; i++) {
//         if(n%i == 0)
//             return false;
//     }
//     return true;
// }
                                    
// int countPrime(int n) {
//     int count = 0;

//     for(int i=2; i<n; i++) {
//         if(isPrime(i))
//             count++;
//     }
//     return count;
// }


// SIEVE OF ERATOSTHENES

int countPrime(int n) {
    int count = 0;
    vector<bool> prime (n+1,true);
    prime[0] = prime[1] = false;

    for(int i=2; i<n; i++) {
        if(prime[i]) {
            count++;

            for(int j=2*i; j<n; j=j+i) {
                prime[j] = false;
            }
        }
    }

    return count;
}

int main() {
    int n;
    cin >> n;

    cout << countPrime(n) << endl;
}