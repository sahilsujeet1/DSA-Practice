#include<bits/stdc++.h>
using namespace std;

void reverse(string& str, int s, int e) {
    while(s <= e)
        swap(str[s++], str[e--]);
}

void reverseWords(string& s) {
    int j=0;

    for(int i=0; i < s.length(); i++) {
        if(s[i] == ' ') {
            reverse(s, j, i-1);
            j = i+1;
        }
        if(i == s.length()-1) {
            reverse(s, j, i);
        }
    }
}

int main()
{
    string s;
    cout << "Enter a sentence: ";
    getline(cin, s);
    reverseWords(s);
    cout << "Output: " << s << endl;
}