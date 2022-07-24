#include <bits/stdc++.h>
using namespace std;

class Normal {
    public:
    // Time Complexity: O(m*n),   Space Complexity: O(1)
    string lCP(vector<string> &arr, int n) {
        string ans = "";
        for(int i=0; i<arr[0].length(); i++) {
            int ch = arr[0][i];
            bool matching = true;
            
            for(int j=1; j<n; j++) {
                if(arr[j].size() < i || ch != arr[j][i]) {
                    matching = false;
                    break;
                }
            }
            
            if(matching)
                ans.push_back(ch);
            else
                break;
        }
        return ans;
    }
};

class TrieNode {
    public:
    char data;
    bool isTerminal;
    int childrenCount;
    TrieNode *children[26];
    
    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        childrenCount = 0;
        
        for(int i=0; i<26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
    public:
    TrieNode *root;
    
    Trie() {
        root = new TrieNode('\0');
    }
    
    void insertWord(string word, TrieNode* root) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        
        int index = word[0]-'a';
        TrieNode *child;
        
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->childrenCount++;
            root->children[index] = child;
        }
        
        insertWord(word.substr(1), child);
    }
    
    void insert(string word) {
        insertWord(word, root);
    }
    
    // Time Complexity: O(m*n),   Space Complexity: O(m*n)
    void lCP(string word, string &ans) {
        TrieNode *temp = root;
        
        for(int i=0; i<word.length(); i++) {
            char ch = word[i];
            
            if(temp->childrenCount == 1) {
                ans.push_back(ch);
                int index = ch - 'a';
                temp = temp->children[index];
            } else {
                break;
            }
            
            if(temp->isTerminal)
                break;
        }
    }
};

string longestCommonPrefix(vector<string> &arr, int n)
{
    // Write your code here
    Normal obj;
    return obj.lCP(arr, n);
    
// Time Complexity: O(m*n),   Space Complexity: O(m*n)
//     Trie *t = new Trie();
//     for(int i=0; i<n; i++) {
//         t->insert(arr[i]);
//     }
    
//     string ans = "";
//     t->lCP(arr[0], ans);
//     return ans;
}


