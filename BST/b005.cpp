// Construction and Conversion of BST
// Sorted array to BST

#include <bits/stdc++.h>
using namespace std;

struct tnode {
	int data;
	tnode *left, *right;
	tnode(int x) {
		data = x;
		left = NULL;
		right = NULL;
	}
};

tnode* arrtobst(int arr[], int l, int r) {
	if(l > r) return NULL;
	int m = l+(r-l)/2;
	tnode *root = new tnode(arr[m]);
	root->left = arrtobst(arr, l, m-1);
	root->right = arrtobst(arr, m+1, r);
	return root;
}

void preorder(tnode *root) {
	if(root==NULL) return;
	cout << root->data << ' ';
	preorder(root->left);
	preorder(root->right);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int arr[] = {1, 2, 3, 4, 5, 6, 7};
	int n = sizeof(arr)/sizeof(arr[0]);
	tnode *root = arrtobst(arr, 0, n-1);
	preorder(root);
	return 0;
}