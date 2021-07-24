#include <iostream>
using namespace std;
#define max 1000
//stack implementation using array and linked list

//Stack implementation using array

class stack {
	int top;
	int a[max];
public:
	stack() { top = -1;}
	bool isEmpty();
	void push(int x);
	void pop();
	void peek();
};

bool stack :: isEmpty() {
	return (top<0);
}

void stack :: push(int x) {
	if(top >= (max-1)) {
		cout << "Stack Overflow\n";
	} else {
		a[++top] = x;
		cout << x << " pushed into stack\n";
	}
}

void stack :: pop() {
	if(this->isEmpty()) {
		cout << "Stack Underflow\n";
	} else {
		int x = a[top--];
		cout << x << " popped from stack\n";
	}
}

void stack :: peek() {
	if(this->isEmpty()) {
		cout << "Stack is Empty\n";
	} else {
		cout << a[top] << " is top of stack\n";
	}
}

//Stack implementation using linked list
class stacknode {
public:
	int data;
	stacknode *next;
};

void push(stacknode** root, int new_data) {
	stacknode* new_node = new stacknode();
	new_node->data = new_data;
	new_node->next = (*root);
	(*root) = new_node;
	cout << new_data << " pushed into stack\n";
}

bool isEmpty(stacknode* root) {
	return (!root);
}

void peek(stacknode** root) {
	if(isEmpty(*root)) {
		cout << "Stack is Empty\n";
	} else {
		cout << (*root)->data << " is top of stack\n";
	}
}

void pop(stacknode** root) {
	if(isEmpty(*root)) {
		cout << "Stack Underflow\n";
	} else {
		stacknode* temp = *root;
		*root = (*root)->next; 
		int x = temp->data;
		cout << x << " popped from stack\n";
	}
}

int main() {
	stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	s.peek();
	s.pop();
	s.peek();
	cout << '\n';
	stacknode* root = NULL;
	push(&root, 11);
	push(&root, 22);
	peek(&root);
	pop(&root);
	pop(&root);
	peek(&root);

	return 0;
}