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
int height(Node *root) {
    if(root==NULL) return 0;
    return max(height(root->left), height(root->right))+1;
}
void A_printGivenLevel(Node *root, int level) {
    if(root==NULL) return;
    if(level==1)
        cout << root->data << ' ';
    else if(level>1) {
        A_printGivenLevel(root->left, level-1);
        A_printGivenLevel(root->right, level-1);
    }
}
void A_printLevelorder(Node *root) {
    for(int i=1; i<=height(root); i++)
        A_printGivenLevel(root, i);
    cout << '\n';
}

// Algorithm B - using queue
void B_printLevelorder(Node *root) {
    if(root==NULL) return;
    queue<Node*> q;
    Node *node = root;
    q.push(node);
    while(!q.empty()) {
        node = q.front();
        cout << node->data << ' ';
        q.pop();
        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    cout << '\n';
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
    B_printLevelorder(root);
    return 0;
}