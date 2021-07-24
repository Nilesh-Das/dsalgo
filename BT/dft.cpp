// Preorder, Inorder and Postorder traversal 
// iterative in a Binary Tree

#include <iostream>
#include <stack>

using namespace std;

struct tnode {
    int data;
    tnode *left, *right;
    tnode(int x) {
        data = x;
        left = right = NULL;
    }
};

void preorder(tnode *root) {
    if(root==NULL) return;
    stack<tnode*> stk;
    tnode *node = root;
    stk.push(node);
    while(!stk.empty()) {
        node = stk.top();
        cout << node->data << ' ';
        stk.pop();
        if(node->right)
            stk.push(node->right);
        if(node->left)
            stk.push(node->left);
    }
    cout << '\n';
}

void inorder(tnode *root) {
    if(root==NULL) return;
    stack<tnode*> stk;
    tnode *node = root;
    while(!stk.empty() || node!=NULL) {
        if(node!=NULL) {
            stk.push(node);
            node = node->left;
        } else {
            node = stk.top();
            stk.pop();
            cout << node->data << ' ';
            node = node->right;
        }
    }
    cout << '\n';
}

void postorder(tnode *root) {
    if(root==NULL) return;
    stack<tnode*> stk1, stk2;
    tnode *node = root;
    stk1.push(node);
    while(!stk1.empty()) {
        node = stk1.top();
        stk1.pop(); stk2.push(node);
        if(node->left)
            stk1.push(node->left);
        if(node->right)
            stk1.push(node->right);
    }
    while(!stk2.empty()) {
        node = stk2.top();
        cout << node->data << ' ';
        stk2.pop();
    }
    cout << '\n';
}

int main() {
    tnode* root = new tnode(1);
    root->left = new tnode(2);
    root->right = new tnode(3);
    root->left->left = new tnode(4);
    root->left->right = new tnode(5);
    cout << "Preorder Traversal:\n";
    preorder(root);
    cout << "Inorder Traversal:\n";
    inorder(root);
    cout << "Postorder Traversal:\n";
    postorder(root);
    return 0;
}
