// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Student
{
    int rollnumber;
    char name[100];
    char phone[100];
    float percentage;
    struct Student *next;
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

// Insert At the Begining 

struct Node *insertAtBegining(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
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

void display()
{
    struct Node * temp = head;
    while(temp!=NULL){
        
        printf("Roll Number: %d\n", temp->rollnumber);
        printf("Name: %s\n", temp->name);
        printf("Phone: %s\n", temp->phone);
        printf("Percentage: %0.4f\n\n", temp->percentage);
        temp = temp->next;
        
    }
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
    // printf("\nElements after the insertion\n");
    // head = insertAtBegining(head, 57);
    // linkedListTraversal(head);

    printf("\nLinked List Elements after deletion\n");
    head = deleteByValue(head, 15);
    linkedListTraversal(head);
}
