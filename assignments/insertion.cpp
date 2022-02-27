#include<stdio.h>
int main(){

  
   int i, j, count, temp, arr[30];

   printf("enter number of elements: ");
   scanf("%d",&count);

   printf("Enter element %d: ", count);
   
   for(i=0;i<count;i++)
      scanf("%d",&arr[i]);

   for(i=1;i<count;i++){
      temp=arr[i];
      j=i-1;
      while((temp<arr[j])&&(j>=0)){
        	arr[j+1]=arr[j];
         j=j-1;
      }
      arr[j+1]=temp;
   }

   printf("Sorted elements: ");
   for(i=0;i<count;i++)
      printf(" %d",arr[i]);

   return 0;
}
