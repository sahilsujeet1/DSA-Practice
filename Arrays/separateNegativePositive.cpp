#include<bits/stdc++.h>
using namespace std;

int main() 
{
    int a[] = {4,-12,3,5,-11,0,5,-4,9,-10};
    int n = 10;
    int j=0;
    for(int i=0; i<n; i++) {
        if(a[i] < 0) {
            if(i != j) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
            j++;
        }
    }

    for(int i=0; i<n; i++) {
        cout << a[i] << " ";
    } cout << endl;
}