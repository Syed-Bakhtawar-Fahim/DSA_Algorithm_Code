// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// define the struct structure
struct Node
{
    int data;
    struct node *next;
};

// Link List Traversal
void linkedListTraversal(struct Node * ptr)
{
    while(ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}


// Main Function
int main() {
   
   // declare the struct variables
   struct Node * head;
   struct Node * second;
   struct Node * third;
   
   // Alocate the memory for the node in the linked list in heap
   head = (struct Node *) malloc(sizeof(struct Node));
   second = (struct Node *) malloc(sizeof(struct Node));
   third = (struct Node *) malloc(sizeof(struct Node));
   
   // Link 1st And 2nd Node
   head->data = 7;
   head->next = second;
   
    // Link 2nd And 3rd Node
   second->data = 11;
   second->next = third;
   
    // Terminate the list at the third node
   third->data = 66;
   third->next = NULL;
   
   // Called linkedListTraversal Function
   linkedListTraversal(head);
   
     
}