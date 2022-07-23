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

    void insertUtil(string word, TrieNode *root) {
        if(word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

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

    bool searchUtil(string word, TrieNode *root) {
        if(word.length() == 0) {
            return root->isTerminal;
        }

        int index = word[0]-'a';
        TrieNode *child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return searchUtil(word.substr(1), child);
    }

    bool searchWord(string word) {
        return searchUtil(word, root);
    }

    void removeUtil(string word, TrieNode* root) {
        if(word.length() == 0) {
            root->isTerminal = false;
            return;
        }

        int index = word[0] - 'a';
        TrieNode *child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        }

        removeUtil(word.substr(1), child);
    }

    void removeWord(string word) {
        removeUtil(word, root);
    }

    bool prefixUtil(string word, TrieNode* root) {
        if(word.length() == 0) {
            return true;
        }

        int index = word[0]-'a';
        TrieNode *child;

        if(root->children[index] != NULL) {
            child = root->children[index];
        } else {
            return false;
        }

        return prefixUtil(word.substr(1), child);
    }

    bool prefixSearch(string word) {
        return prefixUtil(word, root);
    }
};

int main() {
    Trie *t = new Trie();

    t->insertWord("sahil");
    t->insertWord("ankit");
    t->insertWord("kumar");
    cout << "Present or not: " <<  (t->searchWord("sahil") ? "YES" : "NO") << endl;

    t->removeWord("sahil");

    cout << "Present or not: " <<  (t->searchWord("sahil") ? "YES" : "NO") << endl;
    cout << "Present or not: " <<  (t->searchWord("kumar") ? "YES" : "NO") << endl;
    
    cout << "Prefix Present or not: " <<  (t->prefixSearch("kum") ? "YES" : "NO") << endl;
}