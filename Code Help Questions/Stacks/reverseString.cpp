#include<bits/stdc++.h>
using namespace std;

void revString(string &s) {
    stack<char> st;

    for(int i=0; i<s.length(); i++) {
        st.push(s[i]);
    }
    s = "";
    while(!st.empty()) {
        s.push_back(st.top());
        st.pop();
    }
}

int main() {
    string s = "Sahil Kumar";

    revString(s);
    cout << "\nReversed String: " << s << endl << endl;
}