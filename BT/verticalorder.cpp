// Level Order Traversal of binary tree

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left, *right;
    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

// Algorithm A - using fn
void findMaxMin(Node *root, int &max, int &min, int &hd) {
    if(root==NULL) return;
    if(hd < min) min = hd;
    else if(hd > max) max = hd;
    findMaxMin(root->left, max, min, hd-1);
    findMaxMin(root->right, max, min, hd+1);
}

void A_printVertical(Node *root, int line, int hd) {
    if(root==NULL) return;
    if(hd==line)
        cout << node->data << ' ';
    A_printVertical(node->left, line, hd-1);
    A_printVertical(node->right, line, hd+1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    Node *root = new Node(1);  
    root->left = new Node(2);  
    root->right = new Node(3);  
    root->left->left = new Node(4);  
    root->left->right = new Node(5);
    A_printLevelorder(root);
    //B_printLevelorder(root);
    return 0;
}