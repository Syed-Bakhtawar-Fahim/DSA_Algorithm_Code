// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct PQueue
{
    int element, priority;
}pq[5];

int rear = -1;

int isEmpty()
{
    if(rear == -1)
        return 1;
    else
        return 0;
}

int isFull()
{
    if(rear == 4)
        return 1;
    else
        return 0;
}

void enQueue(int element, int priority)
{
    if(isFull())
        printf("PQueue is Overflow\n");
        
    else
        rear++;
        pq[rear].element = element;
        pq[rear].priority = priority;
}

int getHighestPriority()
{
    int i, p = -1;
    if(!isEmpty())
    {
        for(i = 0; i <=rear ; i++)
        {
            if(pq[i].priority > p)
                p = pq[i].priority;
        }
    }
    return p;
}

int deleteHighestPriority()
{
    int i, j, p, element;
    p = getHighestPriority();
    for(i = 0; i <= rear; i++)
    {
        if(pq[i].priority == p)
            element = pq[i].element;
            break;
    }
    
    if(i < rear)
    {
        for(j = i; j < rear; j++)
        {
            pq[j].element = pq[j + 1].element;
            pq[j].priority = pq[j + 1].priority;
            
        }
    }
    rear--;
    return element;
}

void display()
{
        int i;
        printf("Priority Queue Elements are: \n");
        for(i = 0; i <= rear; i++)
        {
            printf("Element is %d and priority is %d: \n", pq[i].element, pq[i].priority);
        }
}








int main() {
    int choice, priority, element;
    
    while(1)
    {
        printf("1. Enqueue an elements with their priority\n");
        printf("2. Get Highest Priority\n");
        printf("3. Dequeue an element\n");
        printf("4. Display all element in a priority queue\n");
        printf("5. Exit\n");
        
        printf("Enter your choice\n");
        scanf("%d ", &choice);
        
        switch(choice)
        {
            case 1:
            printf("Enter an element: ");
            scanf("%d ", &element);
            printf("Enter Priority: ");
            scanf("%d ", &priority);
            enQueue(element, priority);
            printf("\n");
            break;    
            
            case 2:
            priority = getHighestPriority();
            printf("Highest Priority is: %d ", priority);
            printf("\n");
            break; 
                   
                
                
            case 3:
            element = deleteHighestPriority();
            printf("Deleted element is: ", element);
            printf("\n");            
            break;
                
            
            case 4:
            display();
            printf("\n");       
                
            case 5:
            exit(1);
            break;
        }
    }
    
    // printf("Hello world");
    
    return 0;
}


