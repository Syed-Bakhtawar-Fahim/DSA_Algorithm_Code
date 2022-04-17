// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node * left;
    struct Node * right;
    char ch;
};
void create(struct Node * head)
{
    struct Node * newNode = NULL;
    struct Node * ptr = NULL;
    
    do
    {
      newNode = (struct Node *)malloc(sizeof(struct Node));
      printf("Enter the elements for list\n");
      scanf("%d", &newNode->data);
      newNode->left = newNode->right = NULL;
      
      if(head == NULL)
      {
        head = newNode;
        ptr = newNode;
      }
      else
      {
        ptr->right = newNode;
        newNode->left = ptr;
        ptr = newNode;
      }
      printf("\nDo you want to enter another element in the list?\n Y/N\n");
      ch = getc("Y");
    } while(ch == 'Y' || ch == 'y');
    puts("Creation is done\n Thank you\n");
    
}

int main() {


}