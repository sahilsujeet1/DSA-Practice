#include<bits/stdc++.h>
using namespace std;

// Using stacks
queue<int> interleaveQueue(queue<int> que) {
    int n = que.size();
    stack<int> s;

    for(int i=0; i<n/2; i++) {
        int v = que.front();
        s.push(v);
        que.pop();
    }

    while(!s.empty()) {
        que.push(s.top());
        s.pop();
    }

    for(int i=0; i<n/2; i++) {
        que.push(que.front());
        que.pop();
    }

    for(int i=0; i<n/2; i++) {
        s.push(que.front());
        que.pop();
    }

    while(!s.empty()) {
        int v = s.top();
        que.push(v);
        s.pop();

        v = que.front();
        que.push(v);
        que.pop();
    }

    return que;

}

int main() {
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    q.push(19);
    q.push(20);

    queue<int> ans = interleaveQueue(q);

    while(!ans.empty()) {
        cout << ans.front() << " ";
        ans.pop();
    } cout << endl;
}