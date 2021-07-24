// Construction and Conversion of BST
// Construct BST from given preorder traversal
// using stack - O(n)
// leetcode: <link>

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left, *right;
	TreeNode(int x) {
		val = x;
		left = right = NULL;
	}
};

class Solution {
public:
	TreeNode* bstFromPreorder(vector<int>& preorder) {
		stack<TreeNode*> stk;
		TreeNode *root = new TreeNode(preorder[0]);
		stk.push(root);
		TreeNode *temp;
		for(int i=1; i<preorder.size(); i++) {
			temp = NULL;
			while(!stk.empty() && preorder[i] > stk.top()->val) {
				temp = stk.top();
				stk.pop();
			}
			if(temp!=NULL) {
				temp->right = new TreeNode(preorder[i]);
				stk.push(temp->right);
			} else {
				stk.top()->left = new TreeNode(preorder[i]);
				stk.push(stk.top()->left);
			}
		}
		return root;
	}

	void inOrder(TreeNode* t) {
		if(t==NULL) return;
		inOrder(t->left);
		cout << t->val << " ";
		inOrder(t->right);
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	Solution s;
	vector<int> v{10, 5, 1, 7, 40, 50};
	TreeNode* t = s.bstFromPreorder(v);
	s.inOrder(t);
	return 0;
}