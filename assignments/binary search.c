#include <stdio.h>
int main()
{
	int flag=0;
	int size;
	printf("enter your array size");
	scanf("%d",&size);
	int tosearch;
	int l=0;
	int r=size-1;
	int mp;
	int arr[size];
	int i;
	for (i=0;i<size;i++)
	{
		printf("Enter your array values:");
		scanf("%d",&arr[i]);
	}
	printf("enter the value to be searched");
	scanf("%d",&tosearch);

	while (l<=r)
	{
		mp=l+r/2;
		if (tosearch==arr[mp])
		{
			printf("the value is found");
			flag=1;
			break;
		}
		if (tosearch<arr[mp])
		{
			r=mp-1;
		}
		   else
            {
                l=mp+1;
            }

    }
	if(flag==0)
	{
		printf("value not found");
	}
	return 0;
}
