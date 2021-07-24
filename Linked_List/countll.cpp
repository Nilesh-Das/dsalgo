// Iterative C++ program to find length 
// or count of nodes in a linked list 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
class Node 
{ 
	public: 
	int data; 
	Node* next; 
}; 

/* Given a reference (pointer to pointer) to the head 
of a list and an int, push a new node on the front 
of the list. */
void push(Node** head_ref, int new_data) 
{ 
	/* allocate node */
	Node* new_node =new Node(); 

	/* put in the data */
	new_node->data = new_data; 

	/* link the old list off the new node */
	new_node->next = (*head_ref); 

	/* move the head to point to the new node */
	(*head_ref) = new_node; 
} 

/* Counts no. of nodes in linked list */
int getCountIter(Node* head) 
{ 
	int count = 0; // Initialize count 
	Node* current = head; // Initialize current 
	while (current != NULL) 
	{ 
		count++; 
		current = current->next; 
	} 
	return count; 
} 

/* Counts the no. of occurrences of a node 
   (search_for) in a linked list (head)*/
int getCountRec(struct Node* head) 
{ 
    // Base case 
    if (head == NULL) 
        return 0; 
  
    // count is 1 + count of remaining list 
    return 1 + getCountRec(head->next); 
} 

/* Driver program to test count function*/
int main() 
{ 
	/* Start with the empty list */
	Node* head = NULL; 

	/* Use push() to construct below list 
	1->2->1->3->1 */
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1);
	push(&head, 3); 

	/* Check the count function */
	cout<<"count of nodes is "<< getCountIter(head); 
	return 0; 
} 

// This is code is contributed by rathbhupendra 
