// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

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
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Insert At the Begining || CASE: 1

struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    return head;
}

// Insert in Between || CASE: 2

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

// Insert At the End || CASE: 3
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

// Insert After A Node || CASE: 4

struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = prevNode->next;
    prevNode->next = ptr;
    return head;
}

// ALL ABOUT DELETION

// Delete the 1t Node || CASE: 1

struct Node *deleteFirstNode(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);
    return head;
}

// Delete the Node in Between || CASE: 2
struct Node *deleteAtIndex(struct Node *head, int index)
{
    struct Node *p = head;
    struct Node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
    return head;
}

// Delte the last Node || CASE: 4
struct Node *deleteAtLast(struct Node *head)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
}
//  Delete a Node with a given value/key/data (First Node With that Value) || CASE: 4
struct Node *deleteByValue(struct Node *head, int value)
{
    struct Node *p = head;
    struct Node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
}

int main()
{

    // Declare the struct Varaible
    struct Node *head;
    struct Node *second;
    struct Node *third;

    // Allocate memory in heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));

    // Link 1st and 2nd Node
    head->data = 7;
    head->next = second;

    // Link 2nd and 3rd
    second->data = 11;
    second->next = third;

    // Link 3rd And Last
    third->data = 15;
    third->next = NULL;

    printf("\nElements before the insertion\n");
    linkedListTraversal(head);
    printf("\nElements after the insertion\n");
    // head = insertAtBegining(head, 57);
    // head = insertAtIndex(head, 57, 2);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, second, 45);
    // linkedListTraversal(head);

    printf("\nLinked List Elements after deletion\n");
    // head = deleteFirstNode(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtLast(head);
    head = deleteByValue(head, 15);
    linkedListTraversal(head);
}
