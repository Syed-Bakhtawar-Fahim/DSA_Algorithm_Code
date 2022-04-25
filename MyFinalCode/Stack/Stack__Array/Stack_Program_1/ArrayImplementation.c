#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int stack__arr[MAX];
int first = -1;

void push(int data)
{
	int i;
	first += 1;
	for(i = first; i > 0; i--)
	    stack__arr[i] = stack__arr[i-1];
	stack__arr[0] = data;
}

void print()
{
	int i;
	if(first == -1)
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
    for(i = 0; i < first; i++)
    {
        stack__arr[i] = stack__arr[i + 1];
    }
    first -=  1;
    return value;
}

int main()
{
    int data;
	push(30);
	push(45);
	push(90);
	data = pop();
	print();
    return 0;
}