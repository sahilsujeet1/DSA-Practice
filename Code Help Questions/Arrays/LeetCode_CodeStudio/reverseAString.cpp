#include<iostream>
using namespace std;

void reverse(char str[], int n) {
    int start = 0, end = n-2;

    while(start <= end) {
        swap(str[start++], str[end--]);
    }
}

int main()
{
    char str[] = "abcdefghijklmnopqrstuvwxyz";
    int n = sizeof(str)/sizeof(str[0]);

    reverse(str, n);
    cout << str;
}