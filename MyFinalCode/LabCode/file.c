#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *newNode(int new_data)
{
    struct Node *new_Node = (struct Node *)malloc(sizeof(struct Node));
    new_Node->data = new_data;
    new_Node->next = NULL;
    return new_Node;
}

// Link List Traversal
void linkedListTraversal(struct Node *head)
{
    struct Node *ptr = head;
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

// Sorted Start
void sorted(struct Node **head_ref, struct Node *new_Node)
{
    struct Node *current;
    if (*head_ref == NULL || (*head_ref)->data >= new_Node->data)
    {
        new_Node->next = *head_ref;
        *head_ref = new_Node;
    }
    else
    {
        current = *head_ref;
        while (current->next != NULL && current->next->data < new_Node->data)
        {
            current = current->next;
        }
        new_Node->next = current->next;
        current->next = new_Node;
    }
}
// Sorted End


int main()
{
    struct Node *head = NULL;
    struct Node *headRev = NULL;
    struct Node *new_node = newNode(5);
    sorted(&head, new_node);
    new_node = newNode(10);
    sorted(&head, new_node);
    new_node = newNode(2);
    sorted(&head, new_node);
    new_node = newNode(100);
    sorted(&head, new_node);
    printf("Sorted Linked List\n");
    linkedListTraversal(head);
    return 0;
}
