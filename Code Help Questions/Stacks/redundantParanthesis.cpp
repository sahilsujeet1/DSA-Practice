#include <bits/stdc++.h>
using namespace std;

bool redundantBrackets(string exp) {
    stack<char> st;

    for(int i=0; i<exp.length(); i++) {
        char ch = exp[i];
        if((ch == '(') || (ch == '+') || (ch == '-') || (ch == '*') || (ch == '/')) {
            st.push(ch);
        } else {

            if(ch == ')') {
                bool isRedundant = true;

                while(st.top() != '(') {
                    char top = st.top();
                    if(ch == ')') {
                        if(top == '+' || top == '-' || top == '*' || top == '/') {
                            isRedundant = false;
                        } 
                    }
                    st.pop();
                }
                if(isRedundant == true) {
                    return true;
                }
                st.pop();
            }
        }
    }
    return false;

}

int main() {
    string input1 = "(a*b+(c/d))";
    string input2 = "((a/b))";

    cout << endl << "Redundant Brackets: " << redundantBrackets(input1) << endl << endl;
    cout << endl << "Redundant Brackets: " << redundantBrackets(input2) << endl << endl;
}