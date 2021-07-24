// Construction and Conversion of BST
// Convert BT to BST

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

void BTtoarr(TreeNode *root, vector<int>& v) {
	if(root==NULL) return;
	BTtoarr(root->left, v);
	v.push_back(root->val);
	BTtoarr(root->right, v);
}

void arrtoBST(vector<int>& v, TreeNode *root, int& i) {
	if(root==NULL) return;
	arrtoBST(v, root->left, i);
	root->val = v[i++];
	arrtoBST(v, root->right, i);
}

void BTtoBST(TreeNode *root) {
	if(root==NULL) return;
	vector<int> v;
	BTtoarr(root, v);
	sort(v.begin(), v.end());
	int i = 0;
	arrtoBST(v, root, i);
}

void printInorder(TreeNode* root) {
	if(root==NULL) return;
	printInorder(root->left);
	cout << root->val << ' ';
	printInorder(root->right);
}

int main() {
	TreeNode* root = new TreeNode(10);
	root->left = new TreeNode(30);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(20);
	root->right->right = new TreeNode(5);

	BTtoBST(root);
	printInorder(root);
	return 0;
}