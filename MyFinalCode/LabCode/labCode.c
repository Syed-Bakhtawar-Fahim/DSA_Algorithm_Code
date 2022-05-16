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

struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    
    if(ptr->data < head->data)
        ptr->data = data;
        ptr->next = head;
    return head;    
        
    // printf("No Result");
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
    second->data = 16;
    second->next = third;

    // Link 3rd And Last
    third->data = 15;
    third->next = NULL;

    if(second->data > head->data)
        printf("%d ", second->data);
    else
        printf("No");



    printf("\nElements before the insertion\n");
    linkedListTraversal(head);
    // printf("\nElements after the insertion\n");
    // head = insertAtBegining(head, 57);
    // head = insertAtIndex(head, 57, 2);
    // head = insertAtEnd(head, 56);
    // head = insertAfterNode(head, second, 45);
    // linkedListTraversal(head);

    // printf("\nLinked List Elements after deletion\n");
    // head = deleteFirstNode(head);
    // head = deleteAtIndex(head, 2);
    // head = deleteAtLast(head);
    // head = deleteByValue(head, 15);
    // linkedListTraversal(head);
}



// void sorted(struct Node ** head_ref, struct Node * new_Node)
// {
//     struct Node * current;
//     if(**head_ref == NULL || Node *head_ref->data >= new_Node->data)
//     {
//         new_Node->next = head_ref;
//         head_ref = new_Node;
//     }
//     else{
//         current = *head_ref;
//         while(current->next != NULL && current->next->data < new_Node->data)
//         {
//             current = current->next;
//         } 
//         new_Node->next = current->next;
//         current->next = new_Node;
//     }
// }



void sorted(struct Node ** head_ref, struct Node * new_Node)
{
    struct Node * current;
    if(*head_ref == NULL || Node (*head_ref)->data >= new_Node->data)
    {
        new_Node->next = *head_ref;
        *head_ref = new_Node;
    }
    else{
        current = *head_ref;
        while(current->next != NULL && current->next->data < new_Node->data)
        {
            current = current->next;
        } 
        new_Node->next = current->next;
        current->next = new_Node;

    }
    

}



struct Node * head = NULL;