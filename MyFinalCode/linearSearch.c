// Online C compiler to run C program online
#include <stdio.h>

int main() {
  int flag = 0;
  int size;
  printf("Enter te size of Array\n");
  scanf("%d", &size);
  
  int array[size];
  int i;
  
  for(i = 0; i < size; i++)
  {
    printf("Enter the values for Array\n");
    scanf("%d", &array[i]);
  }
  
 int toSearch;
 printf("Enter the value for search in an array\n");
 scanf("%d", &toSearch);
 
 for(int j = 0; j < size; j++)
 {
     if(toSearch == array[j])
     {
         printf("Value found at index %d", j);
         flag = 1;
         break;
     }
 }
  if(flag == 0)
  {
      printf("Value Not in the array");
  }
  
  
}