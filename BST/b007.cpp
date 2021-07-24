// Construction and Conversion of BST
// Sum to the right from each node

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

void RinorderUtil(tnode *root, int &sum) {
    if(root==NULL) return;
    RinorderUtil(root->right, sum);
    sum = sum + root->data;
    root->data = sum - root->data;
    RinorderUtil(root->left, sum);
}

void Rinorder(tnode *root) {
    int sum = 0;
    RinorderUtil(root, sum);
}

void printInorder(tnode *root) {
    if(root==NULL) return;
    printInorder(root->left);
    printf("%6d ",root->data);
    printInorder(root->right);
}

int main() {
    tnode *root = new tnode(11);
    root->left = new tnode(2);
    root->left->left = new tnode(1);
    root->left->right = new tnode(7);
    root->right = new tnode(29);
    root->right->left = new tnode(15);
    root->right->right = new tnode(40);
    root->right->right->left = new tnode(35);
    printInorder(root); puts("");
    Rinorder(root);
    printInorder(root); puts("");
    return 0;
}