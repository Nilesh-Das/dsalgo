// A complete working C++ program to demonstrate 
// all insertion methods on Linked List 
#include <bits/stdc++.h> 
using namespace std; 

// A linked list node 
class Node 
{ 
    public: 
    int data; 
    Node *next; 
}; 

/* Given a reference (pointer to pointer) 
to the head of a list and an int, inserts 
a new node on the front of the list. */
void push(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node(); 

    /* 2. put in the data */
    new_node->data = new_data; 

    /* 3. Make next of new node as head */
    new_node->next = (*head_ref); 

    /* 4. move the head to point to the new node */
    (*head_ref) = new_node; 
} 

/* Given a node prev_node, insert a new node after the given 
prev_node */
void insertAfter(Node* prev_node, int new_data) 
{ 
    /*1. check if the given prev_node is NULL */
    if (prev_node == NULL) 
    { 
        cout<<"the given previous node cannot be NULL"; 
        return; 
    } 

    /* 2. allocate new node */
    Node* new_node = new Node(); 

    /* 3. put in the data */
    new_node->data = new_data; 

    /* 4. Make next of new node as next of prev_node */
    new_node->next = prev_node->next; 

    /* 5. move the next of prev_node as new_node */
    prev_node->next = new_node; 
} 

/* Given a reference (pointer to pointer) to the head 
of a list and an int, appends a new node at the end */
void append(Node** head_ref, int new_data) 
{ 
    /* 1. allocate node */
    Node* new_node = new Node(); 

    Node *last = *head_ref; /* used in step 5*/

    /* 2. put in the data */
    new_node->data = new_data; 

    /* 3. This new node is going to be 
    the last node, so make next of 
    it as NULL*/
    new_node->next = NULL; 

    /* 4. If the Linked List is empty, 
    then make the new node as head */
    if (*head_ref == NULL) 
    { 
        *head_ref = new_node; 
        return; 
    } 

    /* 5. Else traverse till the last node */
    while (last->next != NULL) 
        last = last->next; 

    /* 6. Change the next of last node */
    last->next = new_node; 
    return; 
}
/*Function to delete node without head pointer given
void deleteNode(Node *node)
{
   // Your code here
    int temp;
    struct Node* pre = node;
    while(node->next)
    {
        temp = node->data;
        node->data=(node->next)->data;
        (node->next)->data=temp;
        node=node->next;
    }
    Node* fast=pre->next;
    while (fast->next)
        {
            pre=pre->next;
            fast=fast->next;
        }    
    pre->next=NULL;
} 
*/
/* Given a reference (pointer to pointer) to the head of a list 
   and a position, deletes the node at the given position */
void deleteNode(struct Node **head_ref, int position) 
{ 
   // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   struct Node* temp = *head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of nodes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct Node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
}  
// This function prints contents of 
// linked list starting from head 
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<" "<<node->data; 
        node = node->next; 
    } 
} 

/* Driver code*/
int main() 
{ 
    /* Start with the empty list */
    struct Node* head = NULL; 
  
    push(&head, 7); 
    push(&head, 1); 
    push(&head, 3); 
    push(&head, 2); 
    push(&head, 8); 
  
    puts("Created Linked List: "); 
    printList(head); 
    deleteNode(&head, 4); 
    puts("\nLinked List after Deletion at position 4: "); 
    printList(head); 
    return 0; 
}