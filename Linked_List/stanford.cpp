// Linked List

#include <bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *next;
	Node(int x) {
		data = x;
		next = NULL;
	} 
};

void Push(Node** head_ref, int x) {
	Node *temp = new Node(x);
	temp->next = *head_ref;
	*head_ref = temp;
}

Node* BuildOneTwoThree() {
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	return head;
}

void PrintList(Node *head) {
	for(Node *curr=head; curr!=NULL; curr=curr->next)
		cout << curr->data << ' ';
	cout << '\n';
}

// 1- Count()
int Count(Node *head, int x) {
	Node *curr;
	int cnt = 0;
	for(curr = head; curr != NULL; curr = curr->next)
		if(curr->data == x) cnt++;
	return cnt;
}

void CountTest() {
	Node *list = BuildOneTwoThree();
	int count = Count(list, 2);
	// cout << count << '\n';
}

// 2- GetNth()
int GetNth(Node *head, int i) {
	Node *curr;
	int cnt = 0;
	for(curr=head; curr!=NULL; curr=curr->next) {
		if(cnt==i)
			return curr->data;
		cnt++;
	}
	assert(0);
}

void GetNthTest() {
	Node *myList = BuildOneTwoThree();
	int lastNode = GetNth(myList, 2);
	// cout << lastNode << '\n';
}

// 3- DeleteList()
void DeleteList(Node** head_ref) {
	Node *curr = *head_ref;
	Node *naxt;
	while(curr!=NULL) {
		naxt = curr->next;
		delete curr;
		curr = naxt;
	}
	*head_ref = NULL;
}

void DeleteListTest() {
	Node *list = BuildOneTwoThree();
	DeleteList(&list);
}

// 4- Pop()
int Pop(Node** head_ref) {
	Node *top = *head_ref;
	int data = top->data;
	*head_ref = top->next;
	delete top;
	return data;
}

int Length(Node* head) {
	int cnt = 0;
	while(head) {
		cnt++;
		head = head->next;
	}
	return cnt;
}

void PopTest() {
	Node *head = BuildOneTwoThree();
	int a = Pop(&head);
	int b = Pop(&head);
	int c = Pop(&head);
	int len = Length(head);
	// printf("%d %d %d %d\n", a, b, c ,len); 
}

// 5- InsertNth()
void InsertNth(Node **head_ref, int i, int data) {
	Node *b = new Node(data);
	Node *a = *head_ref;
	if(a==NULL) {
		*head_ref=b;
		return;
	}
	int index = 0;
	while(a) {
		if(index+1 == i) {
			Node *c = a->next;
			a->next = b;
			b->next = c;
			return;
		}
		index++;
		a = a->next;
	}
}

void InsertNthTest() {
	Node *head = NULL;
	InsertNth(&head, 0, 13);
	InsertNth(&head, 1, 42);
	InsertNth(&head, 1, 5);
	PrintList(head);
	DeleteList(&head);
}

// 6- SortedInsert()
void SortedInsert(Node **head_ref, Node* newn) {
	Node **curr = head_ref;
	while(*curr!=NULL && (*curr)->data < newn->data)
		curr = &((*curr)->next);
	newn->next = *curr;
	*curr = newn;
}

void SortedInsertTest() {
	Node *head = NULL;
	Node *a = new Node(3);
	Node *b = new Node(2);
	Node *c = new Node(5);
	SortedInsert(&head, a);
	SortedInsert(&head, b);
	SortedInsert(&head, c);
	PrintList(head);
}

// 7- InsertSorted()
void InsertSorted(Node** head_ref) {
	Node *sort = NULL;
	Node *next;
	for(Node *curr = *head_ref; curr!=NULL; curr=next) {
		next = curr->next;
		SortedInsert(&sort, curr);
	}
	*head_ref = sort;
}

void InsertedSortTest() {
	Node *head = NULL;
	Push(&head, 3);
	Push(&head, 2);
	Push(&head, 5);
	PrintList(head);
	InsertSorted(&head);
	PrintList(head);
}

// 8- Append()
void Append(Node **a, Node **b) {
	Node *cct = *a;
	while(cct)
}



int main() {
	// CountTest();
	// GetNthTest();
	// DeleteListTest();
	// PopTest();
	// InsertNthTest();
	// SortedInsertTest();
	// InsertedSortTest();

	return 0;
}