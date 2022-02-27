#include <stdio.h>
int main()
{

    int size;
    printf("Enter the size of an array\n");
    scanf("%d", &size);

    int array[size];

    for (int i = 0; i < size; i++)
    {
        printf("Enter the value for an array\n");
        scanf("%d", &array[i]);
    }

    int a;
    printf("Ascending or descending [1,0] respecively\n");
    scanf("%d", &a);

    if (a == 1)
    {
        int j;
        for (j = 0; j < size - 1; j++)
        {
            int k;
            for (k = 0; k < size - j - 1; k++)
            {
                if (array[k] < array[k + 1])
                {
                    int temp;
                    temp = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = temp;
                }
            }
        }
        int f;
        for (f = 0; f < size; f++)
        {
            printf("%d", array[f]);
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
                if (array[k] > array[k + 1])
                {
                    int temp;
                    temp = array[k];
                    array[k] = array[k + 1];
                    array[k + 1] = temp;
                }
            }
        }
        int f;
        for (f = 0; f < size; f++)
        {
            printf("%d", array[f]);
            printf("\n");
        }
        return 0;
    }
}