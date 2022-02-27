#include<stdio.h>
int main()
{
    int flag=0;
    int size;
    printf("Enter size of the array" );
    scanf("%d",&size);
    int array[size];
    int i;
    for (i=0;i<size;i++)
        {   printf("enter the values of array");
            scanf("%d",&array[i]);
        }
    int toselect;
    printf("enter the value to be searched");
    scanf("%d",&toselect);
    int j;
    for (j=0;j<size;j++)
    {
        if(toselect==array[j])
            {
                printf("the value is found");
                flag=1;
                break;
        }
}
    if(flag==0)
        {
        printf("value not found");
        }
}
