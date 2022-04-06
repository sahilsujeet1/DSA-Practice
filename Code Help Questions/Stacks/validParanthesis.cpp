#include <bits/stdc++.h>
using namespace std;

bool validParanthesis(string exp) {
    stack<char> st;

    for(int i=0; i<exp.length(); i++) {
        if((exp[i] == '(') || (exp[i] == '{') || (exp[i] == '[')) {
            st.push(exp[i]);
        } else {
            if(!st.empty()) {
                if((exp[i] == ')' && st.top() == '(') || (exp[i] == '}' && st.top() == '{') || (exp[i] == ']' && st.top() == '[')) {
                    st.pop();
                } else {
                    return false;
                }
            } else
                return false;
        }
    }

    if(st.empty())
        return true;
    else    
        return false;
}

int main() {
    string input = "{{}}([])";
    // cin >> input;

    cout << endl << "Valid paranthesis: " << validParanthesis(input) << endl << endl;
}