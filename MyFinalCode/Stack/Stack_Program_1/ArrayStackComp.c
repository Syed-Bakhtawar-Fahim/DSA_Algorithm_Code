#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack__arr[MAX];
int first = -1;

int isEmpty()
{
	if(first == -1)
		return 1;
	else
		return 0;
}
int isFull()
{
	if(first == MAX -1)
		return 1;
	else
		return 0;
}

void push(int data)
{
	int i;
	if(isFull())
	{
		printf("Stack Overflow\n");
		exit(1);
	}
	first += 1;
	for(i = first; i > 0; i--)
	    stack__arr[i] = stack__arr[i-1];
	stack__arr[0] = data;
}

void print()
{
	int i;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	for(i = 0; i <= first; i++)
	{
		printf("%d ", stack__arr[i]);
	}
}

int pop()
{
    int i, value;
    value = stack__arr[0];
    if(isEmpty())
    {
    	printf("Stack Underflow\n");
    	exit(1);
	}
    for(i = 0; i < first; i++)
    {
        stack__arr[i] = stack__arr[i + 1];
    }
    first -=  1;
    return value;
}

int peek()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return stack__arr[0];
}

int main() {
   int choice, data;
   while(1)
   {
       printf("1. Push\n");
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
       printf("The Top most element of the stack is %d ", peek());
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

