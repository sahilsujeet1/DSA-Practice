#include<bits/stdc++.h>
using namespace std;

int doUnion(int a[], int n, int b[], int m) {
    int count=0;
    if(n >= 1) count = 1;
    sort(a,a+n);
    sort(b,b+m);

    for(int i=0; i<n-1; i++) {
        if(a[i] != a[i+1]) count++;
    }

    if(!binary_search(a,a+n,b[0])) count++;

    for(int i=0; i<m-1; i++) {
        if(b[i] != b[i+1]) {
            if(!binary_search(a,a+n,b[i+1])) count++;
        }
    }
    
    return count;
}

int main()
{
    int x,y;
    int a[] = {5,2,6,4,7,8};
    x = sizeof(a)/sizeof(a[0]);
    int b[] = {2,4,8,0};
    y = sizeof(b)/sizeof(b[0]);

    cout << doUnion(a,x,b,y) << endl;

}