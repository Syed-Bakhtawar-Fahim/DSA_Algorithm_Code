#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack__arr[MAX];
int top = -1;

// isFull Function Start
int isFull()
{
    if(top == MAX -1)
        return 1;
    else
        return 0;
}
// isFull Function End

// isEmpty Function Start
int isEmpty()
{
    if(top == -1)
        return 1;
    else
        return 0;
}
// isEmpty Function End

void push(int data)
{
    if(isFull())
    {
        printf("Stack Overflow\n");
        return;
    }
    top = top + 1;
    stack__arr[top] = data;
}

// Pop function
int pop()
{
    int value;
    // If stack is underflow 
    if(isEmpty())
    {
       printf("Stack Underflow\n");
       exit(1);
    }
    value = stack__arr[top];
    top = top - 1;
    return value;
}
// Peek Function Start -- return top value
int peek()
{
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    return stack__arr[top];
}
// Peek Function End


// Print 
void print()
{
    int i;
    if(top == -1)
    {
        printf("Stack Underflow\n");
        return;
    }
    for(i = top; i >= 0; i--)
    {
        printf("%d ", stack__arr[i]);
        // printf("\n");
    }
}

int main() {
   int choice, data;
   while(1)
   {
       printf("\n1. Push\n");
       printf("2. Pop\n");
       printf("3. Print the top element\n");
       printf("4. Print all the elements in stack\n");
       printf("5. Quit");
       printf("\nEnter your Choice\n");
       scanf("%d", &choice);
   
   
   switch(choice)
   {
       case 1:
       printf("Enter the element to be pushed: ");
       printf("\n");
       scanf("%d", &data);
       push(data);
       break;
       
       case 2:
       data = pop();
       printf("Deleted elements is %d\n", data);
       break;
       
       case 3:
       printf("The Top most element of the stack is %d\n", peek());
       break;
       
       case 4:
       print();
       
       
       case 5:
       exit(1);
       
       default:
       printf("Wrong Choice\n");
       
   }
}
  
  return 0;
}