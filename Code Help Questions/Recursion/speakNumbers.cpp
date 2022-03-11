#include<iostream>
using namespace std;

void speak(int n, string arr[]) {
    if(n == 0) return;

    int r = n%10;
    n = n/10;

    speak(n, arr);
    cout << arr[r] << " ";
}

string speakString(int n, string arr[]) {
    string ans;
    if(n == 0)
        return "";

    int r = n%10;
    n = n/10;
    ans = ans + speakString(n, arr) + arr[r] + " ";
    return ans;
}

int main() {
    int n;
    string names[] = {"Zero","One", "Two", "Three", "Four", "Five","Six", "Seven", "Eight", "Nine"};
    cin >> n;

    cout << "\nSpeaking: ";
    speak(n, names);

    // returning string from function
    cout << "\nSpeaking: " << speakString(n, names) << endl;
}