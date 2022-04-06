#include <bits/stdc++.h>
using namespace std;

void sortedInsert(stack<int> &st, int num) {
    if(st.empty() || (!st.empty() && num < st.top())) {
        st.push(num);
        return;
    }

    int n = st.top();
    st.pop();
    sortedInsert(st, num);
    st.push(n);
}

void sortStack(stack<int> &st) {
    if(st.empty()) {
        return;
    }

    int num = st.top();
    st.pop();
    sortStack(st);
    sortedInsert(st, num);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(28);
    st.push(9);
    st.push(-1);

    sortStack(st);

    cout << endl;
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl << endl;
}