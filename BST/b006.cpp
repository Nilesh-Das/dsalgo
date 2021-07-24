// Construction and Conversion of BST
// Construction of BST from BT

#include <bits/stdc++.h>
using namespace std;

struct tnode {
    int data;
    tnode *left, *right;
    tnode(int x) {
        data = x;
        left = right = NULL;
    }
};

void bttoarr(tnode *root, vector<int>& v) {
    if(root==NULL) return;
    bttoarr(root->left, v);
    v.push_back(root->data);
    bttoarr(root->right, v);
}

void arrtobst(vector<int>& v, tnode *root, int& i) {
    if(root==NULL) return;
    arrtobst(v, root->left, i);
    root->data = v[i++];
    arrtobst(v, root->right, i);
}


void bttobst(tnode *root) {
    if(root==NULL) return;
    vector<int> v;
    bttoarr(root, v);
    sort(v.begin(), v.end());
    int i=0;
    arrtobst(v, root, i);
}

void inorder(tnode *root) {
    if(root==NULL) return;
    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    tnode *root = new tnode(10);
    root->left = new tnode(30);
    root->right = new tnode(15);
    root->left->left = new tnode(20);
    root->right->right = new tnode(5);
    bttobst(root);
    inorder(root);

    return 0;
}