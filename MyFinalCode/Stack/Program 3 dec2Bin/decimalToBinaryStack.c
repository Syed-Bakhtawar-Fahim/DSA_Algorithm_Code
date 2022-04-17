#include <stdio.h>
#include <stdlib.h>
#define MAX 100

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

// Decimal To Binary Convertot Fucntion Start

void dec2bin(int n)
{
    while(n != 0)
    {
        push(n%2);
        n = n/2;
    }
}

// Decimal To Binary Convertot Function End

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
    if(isEmpty())
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    while(!isEmpty())
    {
        printf("%d", pop());
    }
}


int main() {
  int dec;
  printf("Please Enter a Decimal Number: ");
  scanf("%d", &dec);
  
  dec2bin(dec);
  print();
  return 0;
}