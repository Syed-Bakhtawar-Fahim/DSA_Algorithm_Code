#include <stdio.h>
int main()
{
	int i;
	int size;
	printf("enter the size of the array");
	scanf("%d", &size);
	int arr[size];
	for (i = 0; i < size; i++)
	{
		printf("enter the value :");
		scanf("%d", &arr[i]);
	}
	int a;
	printf("you want to sort in ascending order or descending order:[0/1]");
	scanf("%d", &a);
	if (a == 1)
	{
		int j;
		for (j = 0; j < size - 1; j++)
		{
			int k;
			for (k = 0; k < size - j - 1; k++)
			{
				if (arr[k] < arr[k + 1])
				{
					int temp;
					temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}
		int f;
		for (f = 0; f < size; f++)
		{
			printf("%d", arr[f]);
			printf("\n");
		}
		return 0;
	}
	if (a == 0)
	{
		int j;
		for (j = 0; j < size - 1; j++)
		{
			int k;
			for (k = 0; k < size - j - 1; k++)
			{
				if (arr[k] > arr[k + 1])
				{
					int temp;
					temp = arr[k];
					arr[k] = arr[k + 1];
					arr[k + 1] = temp;
				}
			}
		}
		int f;
		for (f = 0; f < size; f++)
		{
			printf("%d", arr[f]);
			printf("\n");
		}
		return 0;
	}
}

// #include <stdio.h>
// int main()
// {
// 	int flag = 0;
// 	int size = 0;

// 	printf("Enter the size of an array\n");
// 	scanf("%d", &size);

// 	int array[size];

// 	for (int i = 0; i < size; i++)
// 	{
// 		printf("Enter the values of an array\n");
// 		scanf("%d", &array[i]);
// 	}

// 	// Declare And Initalized a choice variable
// 	int a;
// 	printf("If you want to sort the array in ascending order or descending order choose [0, 1] respectively\n ");
// 	scanf("%d", &a);
// 	// For asscending order
// 	if (a == 1)
// 	{
// 		for (int i = 0; i < size - 1; i++)
// 		{
// 			for (int j = 0; j < size - 1 - i; j++)
// 			{
// 				if (array[j] > array[j + 1])
// 				{
// 					int temp = array[j];
// 					array[j] = array[j + 1];
// 					array[j + 1] = temp;
// 					flag = 1;
// 				}
// 			}
// 			if (flag == 0)
// 			{
// 				break;
// 			}
// 		}
// 	}
// }