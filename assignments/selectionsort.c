
#include<stdio.h>
void main()
{	
	int size;
	printf("enter the size of the array");
	scanf("%d",&size);
	int arr[size];
	int i;
	for(i=0;i<size;i++)
	{
		printf("enter the value of array");
		scanf("%d",&arr[i]);
	}
	printf("you want to sort the array in ascending or descending order[0/1]:");
	int a;
	scanf("%d",&a);
	int smallest;
	if(a==0)
	{
		
		int j;
		for(j=0;j<size-1;j++)
		{
			smallest=j;
			int k;
			for(k=j+1;k<size;k++)
			{
				if(arr[smallest]>arr[k])
				{
					smallest=k;
				}
			}	
			int swap;
			swap=arr[j];
			arr[j]=arr[smallest];
			arr[smallest]=swap;
		}
		int f;
		printf("sorted in ascending order:");
		for (f=0; f< size; f++)
		{
		    printf("%d ", arr[f]);
    		printf("\n");
    	}
	}
	else
	{
		int j;
		for(j=0;j<size-1;j++)
		{
			smallest=j;
			int k;
			for(k=j+1;k<size;k++)
			{
				if(arr[smallest]<arr[k])
				{
					smallest=k;
				}
			}	
			int swap;
			swap=arr[j];
			arr[j]=arr[smallest];
			arr[smallest]=swap;
		}
		int f;
		printf("sorted in descending order:");
		printf("\n");
		for (f=0; f< size; f++)
		{
        	printf("%d ", arr[f]);
    		printf("\n");
    	}
	}
	getch();
}
