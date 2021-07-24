// Construction and Conversion of BST
// Sorted linked list to BST

#include <bits/stdc++.h>
using namespace std;


struct lnode {
	int data;
	lnode* next;
	lnode(int x) {
		data = x;
		next = NULL;
	}
};

struct tnode {
	int data;
	tnode *left, *right;
	tnode(int x) {
		data = x;
		left = right = NULL;
	}
};

int countl(lnode* head) {
	int count = 0;
	while(head!=NULL) {
		count++;
		head = head->next;
	}
	return count;
}

tnode* lltobstutil(lnode** head_ref, int n) {
	if(n<=0) return NULL;
	tnode *left = lltobstutil(head_ref, n/2);
	tnode *root = new tnode((*head_ref)->data);
	root->left = left;
	*head_ref = (*head_ref)->next;
	root->right = lltobstutil(head_ref, n-n/2-1);
	return root;
}

tnode* lltobst(lnode *head) {
	int n = countl(head);
	return lltobstutil(&head, n);
}


void push(lnode** head_ref, int x) {
	lnode *new_node = new lnode(x);
	new_node->next = *head_ref;
	*head_ref = new_node;
}

string serialize(tnode* root) {
	string res;
	queue<tnode*> q;
	q.push(root);
	tnode *curr;

	while(!q.empty()) {
		curr = q.front();
		q.pop();

		if(curr != NULL) {
			res += to_string(curr->data) + ",";

			q.push(curr->left);
			q.push(curr->right);
		} else {
			res += "#,";
		}
	}
  res.pop_back(); // last comma
  return res;
}


void printl(lnode *head) {
	while(head!=NULL) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "NULL\n";
}

void solve() {
	lnode *head = NULL;
	int n; cin >> n;
	for(int i = 0; i < n; i++) {
		int x; cin >> x;
		push(&head, x);
	}
	cout << "Given linked list:\n";
	printl(head);
	tnode *root = lltobst(head);
	cout << "Level order traversal of constructed BST:\n";
	cout << serialize(root) << "\n\n\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	int t; cin >> t;
	while(t--) solve();

	return 0;
}