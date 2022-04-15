#include <bits/stdc++.h>
using namespace std;

queue<int> modifyQueue(queue<int> q, int k);

int main() {
    queue<int> q;
    int k = 3;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    
    queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
}

queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> s;
    
    for(int i=0; i<k; i++) {
        s.push(q.front());
        q.pop();
    }
    
    while(!s.empty()) {
        q.push(s.top());
        s.pop();
    }
    
    int t=q.size()-k;
    while(t--) {
        q.push(q.front());
        q.pop();
    }
    
    return q;
}