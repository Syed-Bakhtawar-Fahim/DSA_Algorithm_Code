#include<stdio.h>
int main()
{
    int a;
    int b;
    a=0;
    b=1;
    int size;
    printf("enter the size of series:");
    scanf("%d",&size);
    printf("%d",a);
    printf("\n");
    printf("%d",b);
    printf("\n");
    int i;
    for(i=0;i<size;i++)
    {
        int c;
        c=a+b;
        printf("%d",c);
        printf("\n");
        a=b;
        b=c;
    }

}
