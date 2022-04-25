#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

char stack[MAX];
char inFix[MAX];
char postFix[MAX];
int top = - 1;

int isFull()
{
	if(top == MAX -1)
		return 1;
	else
		return 0;
}

int isEmpty()
{
	if(top == -1)
		return 1;
	else
		return 0;
}
int precedence(char symbol)
{
	switch(symbol)
	{
		case '^':
			return 3;
			
		case '*':
		case '/':
			return 2;
		
		case '+':
		case '-':
			return 1;
			
		default:
			return 0;
	}
}

int space(char c)
{
	if(c == ' ' || c == '\t')
		return 1;
	else
		return 0;
}
void push(char c)
{
	if(isFull())
	{
		printf("Stack Overflow\n");
		return;
	}
	top = top + 1;
	stack[top] = c;
}

char pop()
{
	char c;
	if(isEmpty())
	{
		printf("Stack Underflow\n");
		exit(1);
	}	
	c = stack[top];
	top = top - 1;
	return c;
		
}



void inToPost()
{
	int i, j = 0;
	char symbol, next;
	for(i = 0; i < strlen(inFix); i++)
	{
		symbol = inFix[i];
		
		// if symbol is not a whitespace
		if(!space(symbol))
		{
			switch(symbol)
		{
			case '(':
				push(symbol);
				break;
			
			case ')':
				while((next = pop()) != '(')
					postFix[j++] = next;
				break;
			
			case '+':
			case '-':
			case '*':
			case '/':
			case '^':
			    while(!isEmpty() && precedence(stack[top]) >= precedence(symbol))
			        postFix[j++] = pop();
			    push(symbol);
			    break;
					
			default:
				postFix[j++] = symbol;
				
			}
		}
	}
	while(!isEmpty())
	{
		postFix[j++] = pop();
	}
	postFix[j] = '\0';
}

// Print Function

void print()
{
	int i;
	printf("The Equivalent Postfix Expression is: ");
	while(postFix[i])
		printf("%c", postFix[i++]);
	
	printf("\n");
}

int main()
{
	printf("Enter the Postfix Expression: ");
	gets(inFix);
	
	inToPost();
	print();
	return 0;
}