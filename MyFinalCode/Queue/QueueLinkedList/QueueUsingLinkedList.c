#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

struct Node * front = NULL;
struct Node * rear = NULL;

// Link List Traversal
void linkedListTraversal(struct Node *ptr)
{
    printf("Printing the element of the Queue Linked List: \n");
    while (ptr != NULL)
    {
        printf("Element: %d \n", ptr->data);
        ptr = ptr->next;
    }
}

void enQueue(int value)
{
    struct Node * n = (struct Node *)malloc(sizeof(struct Node));
    // This is dynamic queue which will never be full but if the computer memory is full then it happen
    if(n == NULL)
    {
        printf("Queue is Full (Queue Overflow)\n");
    }
    else
    {
        n->data = value;
        n->next = NULL;
        
        if(front == NULL)
        {
            front = rear = n;
        }
        else
        {
            rear->next = n;
            rear = n;
        }
    }
}

int deQueue()
{
    int a = -1;
    struct Node * ptr = front;
    
    // If Queue is Empty
    if(front == NULL)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        front = front->next;
        a = ptr->data;
        free(ptr);
    }
    return a;
}

int main()
{
    linkedListTraversal(front);
    // printf("Dequeuing element is %d\n", deQueue()); underflow
    enQueue(2);
    enQueue(3);
    enQueue(4);
    enQueue(5);
    enQueue(6);
    enQueue(7);
    printf("Dequeuing element is %d\n", deQueue());
    printf("Dequeuing element is %d\n", deQueue());
    printf("Dequeuing element is %d\n", deQueue());
    printf("Dequeuing element is %d\n", deQueue());
    linkedListTraversal(front);
    
    return 0;
}