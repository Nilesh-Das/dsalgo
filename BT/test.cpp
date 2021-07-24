#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct Tree {
  Tree *left, *right;
  char data;
  Tree(char x) : data(x), left(NULL), right(NULL){}
};

void levelOrderTraversal(Tree* root) {
  if(!root) return;
  queue<pair<Tree*, int>> q;
  int h;
  q.push(make_pair(root,0));
  while(!q.empty()) {
    auto node = q.front(); q.pop();
    if(root==node.first)
      cout << (node.first)->data;
    else
      cout << (h==node.second?' ':'\n') << (node.first)->data;
    if((node.first)->left) q.push(make_pair((node.first)->left,node.second+1));
    if((node.first)->right)q.push(make_pair((node.first)->right,node.second+1));
    h = node.second;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  
  Tree* root = new Tree('A');
  root->left = new Tree('B');
  root->right = new Tree('C');
  root->left->left = new Tree('D');
  root->left->left->left = new Tree('G');
  root->left->right = new Tree('E');
  root->right->left = new Tree('F');
  levelOrderTraversal(root);
  return 0;
}