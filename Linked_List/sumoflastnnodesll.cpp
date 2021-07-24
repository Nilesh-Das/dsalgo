#include <iostream>
using namespace std;

struct Node 
{
	int data; 
	Node* next; 
}; 

void push(Node** head_ref, int new_data)
{ 
	Node* newn = new Node();
  newn->data = new_data;
  newn->next = *head_ref;
  *head_ref = newn; 
} 


int sumOfLastN_Nodes(struct Node* head, int n)
{
  Node* tmp = head;
  while(n--) {
    head = head->next;
  }

  for(; head; head=head->next) {
    tmp = tmp->next;
  }

  int sum = 0;
  for(; tmp; tmp=tmp->next) {
    sum += tmp->data;
  }

  return sum;
}

int main()
{
	/* Start with the empty list */
	Node* head = NULL; 

	/* Use push() to construct below list 
	3->1->2->1->3->1 */
	push(&head, 1); 
	push(&head, 3); 
	push(&head, 1); 
	push(&head, 2); 
	push(&head, 1);
	push(&head, 3); 

	printf("%d", sumOfLastN_Nodes(head, 3));
}