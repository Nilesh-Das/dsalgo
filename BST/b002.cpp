// Construction and Conversion of BST
// construct BST from given preorder traversal
// leetcode: <link>

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) {
        val = x;
        left = right = NULL;
    }
};

class Solution {
public:
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int bound=INT_MAX) {
        if(i>=preorder.size() || preorder[i]>bound) return NULL;
        TreeNode* t = new TreeNode(preorder[i++]);
        t->left = bstFromPreorder(preorder, t->val);
        t->right = bstFromPreorder(preorder, bound);
        return t;
    }

    void printInorder(TreeNode* t) {
        if(t==NULL) return;
        printInorder(t->left);
        cout << t->val << " ";
        printInorder(t->right);
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    Solution s;
    vector<int> v{10, 5, 1, 7, 40, 50};
    TreeNode* t = s.bstFromPreorder(v);
    s.printInorder(t);
    return 0;
}