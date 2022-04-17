#include <stdio.h>
#include <stdlib.h>
#define MAX 50

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

// Prime Factor Fucntion Start

void primeFact(int num)
{
	int i = 2;
	while(num != 1)
	{
		while(num % i == 0)
		{
			push(i);
			num = num / i;
		}
		i++;
	}
	printf("Prime factors of the number in descending order are as follow: ");
	while(top != -1)
	{
		printf("%d ", pop());
	}
}
// Prime Factor Function End

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
//  int number;
//  printf("Please Enter a Positive Number: ");
//  scanf("%d", &number);
  
  primeFact(12);
  return 0;
}