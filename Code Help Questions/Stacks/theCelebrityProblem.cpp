#include<bits/stdc++.h>
using namespace std;

int getCelebrity(vector<vector<int>> M, int n) {
    stack<int> s;
    for(int i=0; i<n; i++) {
        s.push(i);
    }
    
    while(s.size() > 1) {
        int a = s.top();
        s.pop();
        
        int b = s.top();
        s.pop();
        
        if(M[a][b] == 1)
            s.push(b);
        else
            s.push(a);
    }
    
    int candidate = s.top();
    int zeroCount = 0, colCount = 0;
    
    for(int i=0; i<n; i++) {
        if(M[candidate][i] == 0)
            zeroCount++;
        
        if(M[i][candidate] == 1)
            colCount++;
    }
    
    if(zeroCount != n || colCount != n-1)
        candidate = -1;
    
    return candidate;
}

int main() {
    vector<vector<int>> M = {
        {0,1,0},
        {0,0,0},
        {0,1,0}
    };

    int n = M.size();

    cout << "\n\nThe celebrity is: " << getCelebrity(M, n) << endl << endl;

    return 0;
}