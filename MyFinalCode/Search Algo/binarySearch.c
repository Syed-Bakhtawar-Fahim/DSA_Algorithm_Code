// Online C compiler to run C program online
#include <stdio.h>

int main() {
 
    int flag = 0;
    int size;
    
    printf("Enter the Size of an array\n");
    scanf("%d", &size);
    
    int array[size];
    int right = size - 1;
    int left = 0;
    int midPoint;
    int toSearch;
    
    
    
    for(int i = 0; i < size; i++)
    {
        printf("Enter the values for an array in sorted form\n");
        scanf("%d", &array[i]);
    }
    
    printf("Enter the Value of search\n");
    scanf("%d", &toSearch);
    
    while(left <= right)
    {
        midPoint = (left + right)/2;
        
        if(toSearch == array[midPoint])
        {
            printf("The value is found at index %d ", array[midPoint]);
            // %d", array[midPoint]
            flag = 1;
            break;
        }
            if(toSearch < array[midPoint])
            {
                right = midPoint - 1;
            }
            if(toSearch > array[midPoint])
            {
                left = midPoint + 1;
            }
    }
    
        if(flag == 0)
        {
            printf("The Value is not in an array\n");
        }


}

