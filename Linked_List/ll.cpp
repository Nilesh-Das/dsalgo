#include<iostream>
using namespace std;

class node
{
	public:
		int data;
		node* next;
};

void printList(node* n) 
{ 
    while (n != NULL) 
    { 
        cout << n->data << " "; 
        n = n->next; 
    } 
}

int main()
{
	node* first = NULL;
	node* second = NULL;
	node* third = NULL;

	first = new node();
	second = new node();
	third = new node();

	first->data = 1;
	first->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;

	printList(first);

	return 0;
}