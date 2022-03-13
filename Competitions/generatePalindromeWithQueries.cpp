#include <bits/stdc++.h>
using namespace std;

string getPalindrome(string str)
{

	// Store counts of characters
	unordered_map<char, int> hmap;
	for (int i = 0; i < str.length(); i++)
		hmap[str[i]]++;

	/* find the number of odd elements.
	Takes O(n) */
	int oddCount = 0;
	char oddChar;
	for (auto x : hmap) {
		if (x.second % 2 != 0) {
			oddCount++;
			oddChar = x.first;
		}
	}

	/* odd_cnt = 1 only if the length of
	str is odd */
	if (oddCount > 1
		|| oddCount == 1 && str.length() % 2 == 0)
		return str;

	/* Generate first halh of palindrome */
	string firstHalf = "", secondHalf = "";
	for (auto x : hmap) {

		// Build a string of floor(count/2)
		// occurrences of current character
		string s(x.second / 2, x.first);

		// Attach the built string to end of
		// and begin of second half
		firstHalf = firstHalf + s;
		secondHalf = s + secondHalf;
	}

	// Insert odd character if there
	// is any
	return (oddCount == 1)
			? (firstHalf + oddChar + secondHalf)
			: (firstHalf + secondHalf);
}

string performQueries(string &s, vector<vector<int>> &a, int n, int q) {
    vector<int> l,r;
    for(auto pair:a) {
        l.push_back(pair[0]-1);
        r.push_back(pair[1]-1);
    }
    
    
    for(int i=0;i<q;i++) {
        string pal = getPalindrome(s.substr(l[i], r[i]-l[i]+1));
        int t = l[i];
        for(int j=0; j<pal.length(); j++) {
            s[t++] = pal[j];
        }
    }
    
    return s;
}

int main()
{
    string str = "llaaqqzz";
    vector<vector<int>> a = {{1,6}, {1,2}, {1,2},{1,8}};
	cout << performQueries(str,a , 8, 4) << endl;
	return 0;
}