#include <iostream>
#include <bits/stdc++.h>
using namespace std;
struct Node{
public:
    int data;
    struct Node* next;
};

void ReverseRecursion(struct Node* p)
{
    if(p->next == NULL)
    {
        head = p;
        return;
    }
    ReverseRecursion(p->next);
    struct Node* q = p->next;
    q->next = p;
    p->next = NULL;
}

struct Node* Reverse(struct Node* head)
{
    struct Node *current, *prev, *next;
    current = head;
    prev = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
    return head;
}
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
void printList(Node *node) 
{ 
    while (node != NULL) 
    { 
        cout<<" "<<node->data; 
        node = node->next; 
    }
    puts("\n");
} 
int main()
{
    struct Node* head = NULL;
    push(&head, 2);
    push(&head, 3);
    push(&head, 4);
    push(&head, 5);
    push(&head, 6);
    puts("orig list:");printList(head);
    head = Reverse(head);
    puts("rev list:");printList(head);
}