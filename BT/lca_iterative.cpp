#include <bits/stdc++.h>
using namespace std;

TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    unordered_map<TreeNode*, TreeNode*> parent;
    stack<TreeNode*> stk;
    parent[root] = NULL;
    stk.push(root);
    while (!parent.count(p) || !parent.count(q)) {
        TreeNode *node = stk.top(); stk.pop();
        if(node->left) { parent[node->left]=node; stk.push(node->left); }
        if(node->right) { parent[node->right]=node; stk.push(node->right); }
    }
    set<TreeNode*> ancestors;
    while (p) { ancestors.insert(p); p=parent[p]; }
    while (!ancestors.count(q)) q = parent[q];
    return q;
}

int main() {
    return 0;
}