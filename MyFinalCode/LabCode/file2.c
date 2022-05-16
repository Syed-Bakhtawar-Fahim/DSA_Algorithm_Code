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
void linkedListTraversal(struct Node *prev)
{
    struct Node *ptr = prev;
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

static void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next = NULL;

    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
    
}

void push(struct Node ** head_ref, int new_data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = new_data;

    newNode->next = (*head_ref);
    (*head_ref) = newNode;
}

int main()
{
    struct Node *head = NULL;

    // push(&head, 20);
    // struct Node *new_node = newNode(50);
    // struct Node *new_node = newNode(111);
    push(&head, 2);
    push(&head, 10);
    push(&head, 5);
    reverse(&head);
    linkedListTraversal(head);
    // reverse(head_ref);
    // getchar();
    return 0;
} 

