#include<bits/stdc++.h>
using namespace std;

void reverseString(string &str, int s, int e) {
    if(s > e)
        return;
    
    swap(str[s], str[e]);
    reverseString(str, ++s, --e);
}

void reverseString1(string &str, int i) {
    if(i > str.length()-1-i)
        return;
    
    swap(str[i], str[str.length()-1-i]);
    reverseString1(str, ++i);
}

int main() {
    string str = "Sahil";
    
    cout << "Original String: " << str << endl;
    
    // reverseString(str, 0, str.length()-1);
    reverseString1(str, 0);
    cout << "Reversed String: " << str << endl;
}