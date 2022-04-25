#include <stdio.h>
#include <stdlib.h>

// Struct Node
struct node
{
    int data;
    struct Node * link;
} *top = NULL;


// isEmpty Code

int isEmpty()
{
	if(top == NULL)
		return 1;
	else
		return 0;
}

// Push Code
void push(int data)
{
    struct node * newNode;
    newNode = malloc(sizeof(newNode));
    if(newNode == NULL)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    newNode->data = data;
    newNode->link = NULL;
    
    newNode->link = top;
    top = newNode;  
}

// Pop Code
int pop()
{
	struct node * temp;
	int value;
	
	if(isEmpty())
	{
		printf("Stack Underflow\n");
	}
	temp = top;
	value = temp->data;
	top = top->link;
	free(temp);
	temp = NULL;
	return value;
}

// Peek Code
int peek()
{
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	return top->data;
}

// Print Code
void print()
{
	struct node * temp;
	temp = top;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}
	printf("The element in the stack are: ");
	while(temp)
	{
		printf("%d ", temp->data);
		temp = temp->link;
	}
	printf("\n");
}

int main()
{
	int choice , data;
	while(1)
	{
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Print the Top most element\n");
		printf("4. Print all the elements\n");
		printf("5. Quit\n"); 
		printf("Enter your Choice: ");
		scanf("%d", &choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter the element to be pushed: ");
				scanf("%d", &data);
				push(data);
				break;
				
			case 2:
				data = pop();
				printf("The Deleted element is %d\n", data);
				break;
				
			case 3:
			 	printf("The Top most element of the stack is %d\n", peek());
       			break;
				
			case 4:
				print();
				break;
				
			case 5:
				exit(1);
				
			default:
				printf("Wrong Choice\n");
				break;
		}
	}
	return 0;
}











