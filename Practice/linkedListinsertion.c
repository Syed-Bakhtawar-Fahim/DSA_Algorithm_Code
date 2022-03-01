// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

// define the struct structure
struct Node
{
    int data;
    struct Node *next;
};

// Link List Traversal
void linkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

// Insertion at the begining
struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Insert in Between
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }

    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Insert At End
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head;

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Insert after a Node
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// Main Function
int main()
{

    // declare the struct variables
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Alocate the memory for the node in the linked list in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

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
    printf("Linked List before insertion\n");
    linkedListTraversal(head);
    //   head = insertAtBegining(head, 57);
    //   head = insertAtIndex(head, 99, 1);
    //   head = insertAtEnd(head, 65);
    // head = insertAfterNode(head, second, 45);
    printf("\nLinked List after insertion\n");
    linkedListTraversal(head);
}
