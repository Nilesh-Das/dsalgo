#include <bits/stdc++.h>
using namespace std;

class Trie {
    Trie* child[26];
    bool end;

public:
    Trie() {
        memset(child, 0, sizeof child);
        end = false;
    }

    void insert(string word) {
        Trie* node = this;
        for(char c : word) {
            c -= 'a';
            if(!node->child[c])
                node->child[c] = new Trie();
            node = node->child[c];
        }
        node->end = true;
    } 

    bool search(string word) {
        Trie* node = this;
        for(char c : word) {
            c -= 'a';
            if(!node->child[c]) return false;
            node = node->child[c];
        }
        return node->end;
    }

    bool startsWith(string prefix) {
        Trie* node = this;
        for(char c : prefix) {
            c -= 'a';
            if(!node->child[c]) return false;
            node = node->child[c];
        }
        return true;
    }

};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    Trie* root = new Trie();
    root->insert("hello");
    root->insert("hey");
    cout << root->search("hello") << '\n';
    cout << root->search("hel") << '\n';
    cout << root->search("his") << '\n';
    cout << root->startsWith("hel") << '\n';
    
    return 0;
}