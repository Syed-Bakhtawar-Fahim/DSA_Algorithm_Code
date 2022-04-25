#include <stdio.h>
#include <stdlib.h>
#define MAX 4

int stack__arr[MAX];
int top = -1;

void push(int data)
{
  if (top == MAX - 1)
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
  if (top == -1)
  {
    printf("Stack Underflow\n");
    exit(1);
  }
  value = stack__arr[top];
  top = top - 1;
  return value;
}

// Print
void print()
{
  int i;
  if (top == -1)
  {
    printf("Stack Underflow\n");
    return;
  }
  for (i = top; i >= 0; i--)
  {
    printf("%d", stack__arr[i]);
    printf("\n");
  }
}

int main()
{
  int data;
  push(1);
  push(2);
  push(3);
  push(4);
  push(5);
  data = pop();
  data = pop();
  // Check that we'll recive the value or not
  //   printf("%d", data);
  print();
  return 0;
}