#include <bits/stdc++.h>
using namespace std;

void solve(stack<int>&stack, int count, int size) {
    if(count == size/2) {
        stack.pop();
        return;
    }
    
    int num = stack.top();
    stack.pop();
    solve(stack, count+1, size);
    stack.push(num);
}

void deleteMiddle(stack<int>&inputStack, int N){
    int count = 0;
	
    solve(inputStack, count, N);
}

int main() {
    stack<int> st;
    st.push(3);
    st.push(5);
    st.push(2);
    st.push(28);
    st.push(9);
    st.push(-1);

    deleteMiddle(st, st.size());

    while(!st.empty()) {
        cout << st.top() << " ";
        st.pop();
    }
}