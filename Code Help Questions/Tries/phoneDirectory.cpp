#include <bits/stdc++.h>
using namespace std;

class TrieNode {
  public:
    char data;
    TrieNode *children[26];
    bool isTerminal;
    
    TrieNode(char ch) {
        data = ch;
        isTerminal = false;
        for(int i=0; i<26; i++)
            children[i] = NULL;
    }
};

class Trie {
    public:
      TrieNode *root = new TrieNode('\0');
    
    void insertUtil(string word, TrieNode *root) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }
        
        TrieNode *child;
        int index = word[0]-'a';
        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }
        
        insertUtil(word.substr(1), child);
    }
    
    void insertWord(string word) {
        insertUtil(word, root);
    }
    
    void printSuggestions(TrieNode *curr, vector<string> &temp, string &prefix) {
        if(curr->isTerminal) {
            temp.push_back(prefix);
        }
        
        for(char ch='a'; ch<='z'; ch++) {
            TrieNode *next = curr->children[ch-'a'];
            if(next != NULL) {
                prefix.push_back(ch);
                printSuggestions(next, temp, prefix);
                prefix.pop_back();
            }
        }
    }
    
    vector<vector<string>> getSuggestions(string str) {
        TrieNode *prev = root;
        vector<vector<string>> output;
        string prefix = "";
        
        for(auto i:str) {
            char lastCh = i;
            prefix.push_back(lastCh);
            
            TrieNode *curr = prev->children[lastCh-'a'];
            if(curr == NULL)
                break;
            
            vector<string> temp;
            printSuggestions(curr, temp, prefix);
            
            output.push_back(temp);
            temp.clear();
            prev = curr;
        }
        
        return output;
    }
};

vector<vector<string>> phoneDirectory(vector<string>&contactList, string &queryStr)
{
    //    Write your code here.
    Trie *t = new Trie();
    for(auto i:contactList) {
        t->insertWord(i);
    }
    
    return t->getSuggestions(queryStr);
}