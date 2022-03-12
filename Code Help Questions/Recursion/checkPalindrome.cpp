#include<bits/stdc++.h>
using namespace std;

bool palindrome(string str, int i) {
    if(i > str.length()-1-i)
        return true;
    
    if(str[i] == str[str.length()-1-i])
        return palindrome(str, ++i);
    else
        return false;
}

int main()
{
    // string str = "malayalam";
    string str = "Sahil";

    cout << "Is the string plaindrome: " << (palindrome(str, 0) == 1 ? "Yes" : "No") << endl; 
}