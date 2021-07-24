// Construction and Conversion of BST
// Top view of Binary Tree

#include<bits/stdc++.h>

using namespace std;

class Node {
public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void topView(Node * root) {
    if(root==NULL) return;
    stack<int> stk;
    Node *rnode = root->right;
    Node *lnode = root->left;
    while(lnode) {
        stk.push(lnode->data);
        lnode = lnode->left;
    }
    while(!stk.empty()) {
        cout << stk.top() << ' ';
        stk.pop();
    }
    cout << root->data << ' ';
    while(rnode) {
        cout << rnode->data << ' ';
        rnode = rnode->right;
    }
}

int main() {
    Node *root = new Node(11);
	root->left = new Node(2);
	root->left->left = new Node(1);
	root->left->right = new Node(7);
	root->right = new Node(29);
	root->right->left = new Node(15);
	root->right->right = new Node(40);
	root->right->right->left = new Node(35);
  
    topView(root);

    return 0;
}
