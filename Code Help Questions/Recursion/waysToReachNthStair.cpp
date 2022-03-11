#include<iostream>
using namespace std;

int ways(int n) {
    if(n < 0)
        return 0;
    if(n == 0)
        return 1;
        
    return ways(n-2) + ways(n-1);
}

int main() {
    int n;
    cin >> n;

    cout << "Number of ways to reach " << n << "th stair by jumping 1 or 2 stairs: " << ways(n) << endl;
}