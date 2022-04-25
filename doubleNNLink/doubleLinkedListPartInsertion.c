// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    struct Node * prev;
    int data;
    struct Node * next;
};

// addToEmpty | CASE: 01

struct Node * addToEmpty(struct Node * head, int data)
{
    struct Node * temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    head = temp;
    return head;
}

// Insert At the Begining |CASE: 02
struct Node * addAtBeg(struct Node * head, int data)
{
    struct Node * temp = malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;
    temp->next = head;
    head->prev = temp;
    head = temp;
    return head;
}

// At End | CASE: 03
struct Node * addToEnd(struct Node * head, int data)
{
    struct Node * temp;
    struct Node * tp;
    temp = malloc(sizeof(struct Node));
    temp->prev =NULL;
    temp->data = data;
    temp->next = NULL;
    tp = head;
    while(tp->next != NULL)
    {
        tp = tp->next;
    }
    tp->next = temp;
    temp->prev = tp;
    return head;
}

// Add After Postion | CASE: 03
struct Node * addAfterPos(struct Node * head, int data, int position)
{
    struct Node * newP = NULL;
    struct Node * temp = head;
    struct Node * temp2 = NULL;
    newP = addToEmpty(newP, data);
    
    while(position != 1)
    {
        temp = temp->next;
        position--;
    }
    if(temp->next == NULL) // LAST NODE
    {
        temp->next = newP;
        newP->prev = temp;
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}

// Add Before Position
struct Node * addBeforePos(struct Node * head, int data, int position)
{
    struct Node * newP = NULL;
    struct Node * temp = head;
    struct Node * temp2 = NULL;
    newP = addToEmpty(newP, data);
    
    while(position > 2)
    {
        temp = temp->next;
        position--;
    }
    if(position == 1)
    {
        head = addAtBeg(head, data);
    }
    else
    {
        temp2 = temp->next;
        temp->next = newP;
        temp2->prev = newP;
        newP->next = temp2;
        newP->prev = temp;
    }
    return head;
}

int main() {
    
    
    struct Node * head = NULL;
    struct Node * ptr;
    int position = 2;
    
    head = addToEmpty(head, 45);
    head = addAtBeg(head, 65);
    head = addToEnd(head, 77);
    head = addAfterPos(head, 24, position);
    head = addBeforePos(head, 23 , position);
    
    ptr = head;
    while(ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
    
    
}







