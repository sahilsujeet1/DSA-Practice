#include<bits/stdc++.h>
using namespace std;

char lower(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) {
        return ch;
    } else {
        return ch - 'A' + 'a';
    }
}

bool validRange(char ch) {
    if((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'))
        return true;
    else 
        return false;
}

bool checkPalindrome(string str)
{
   int s=0, e=str.length()-1;
   while(s <= e) {
       while(!validRange(str[s])) {
           s++;
           if(s >= str.length()-1) return 1;
       }
       while(!validRange(str[e])) e--;


       if(lower(str[s]) == lower(str[e])) {
           s++;
           e--;
       } else {
           return 0;
       }
   }
   return 1;
}

int main()
{
    // string s = "c1 0$d@eeD 01c";
    // string s = "/ mala $%Y ^ *) A__+la= @M";
    int t;
    cin >> t;
    cin.ignore();
    cout << endl;
    for(int i=0; i<t; i++) {
        string s;
        getline(cin, s);

        cout << "Palindrome of " << s << ":  " << ((checkPalindrome(s) == 1) ? "YES" : "NO") << endl;
    }
    
}