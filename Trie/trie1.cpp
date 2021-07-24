#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    bool end;

    TrieNode() {
        memset(child, 0, sizeof child);
        end = false;
    }
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode *p = root;
        
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';
            if(p->child[idx] == NULL)
                p->child[idx] = new TrieNode();
            p = p->child[idx];
        }
        p->end = true;
    }

    bool search(string word) {
        TrieNode *p = root;
        for(int i=0; i<word.length(); i++) {
            int idx = word[i] - 'a';
            if(!p->child[idx]) return false;
            p = p->child[idx];
        }
        return p->end;
    }

    bool startsWith(string prefix) {
        TrieNode *p = root;
        for(int i=0; i<prefix.length(); i++) {
            int idx = prefix[i] - 'a';
            if(!p->child[idx]) return false;
            p = p->child[idx];
        }
        return true;
    }
};


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    return 0;
}