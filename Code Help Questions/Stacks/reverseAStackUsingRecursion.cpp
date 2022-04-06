#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int>& stack, int n) {
    if(stack.empty()) {
        stack.push(n);
        return;
    }

    int num = stack.top();
    stack.pop();
    insertAtBottom(stack, n);
    stack.push(num);
}

void reverseStack(stack<int> &stack)  {
    if(stack.empty()) {
        return;
    }

    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(28);
    st.push(9);
    st.push(-1);

    reverseStack(st);

    cout << endl;
    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl << endl;
}