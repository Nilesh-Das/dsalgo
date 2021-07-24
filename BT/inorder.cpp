#include <bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//recursive inorder algo
//inorder(node)
//  if(node==null)
// 		return
// 	inoder(node.left)
// 	visit(node)
// 	inorder(node.right)

class SolutionR {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;

		inorderTraversal(root, ans);
		return ans;
	}

	void inorderTraversal(TreeNode* root, vector<int> &ans) {
		if (root == NULL) return;
		inorderTraversal (root->left, ans);
		ans.push_back(root->val);
		inorderTraversal (root->right, ans);
	}
};


// iterative inorder algo
// iterativeInorder(node)
//   s ← empty stack
//   while (not s.isEmpty() or node ≠ null)
//     if (node ≠ null)
//       s.push(node)
//       node ← node.left
//     else
//       node ← s.pop()
//       visit(node)
//       node ← node.right

class SolutionI {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> ans;
		if (root == NULL) return ans;

		stack<TreeNode *> stk;  
		TreeNode* node = root;
		while (!stk.empty() || node != NULL) {
			if (node != NULL) {
				stk.push(node);
				node = node->left;
			} else {
				node = stk.top();
				stk.pop();
				ans.push_back(node->val);
				node = node->right;
			}
		}
		return ans;
	}
};


int main() {
	
	return 0;
}
