#include <stdio.h>

int binarysearch(int *num, int l, int r, int search_num)
{
    int flag = 0;
    if (l <= r)
    {
        int mp = (l + r) / 2;
        if (search_num == num[mp])
        {
            flag = 1;
            return mp;
        }
        else if (search_num > num[mp])
        {
            return binarysearch(num, mp + 1, r, search_num);
        }

        else if (search_num < num[mp])
        {
            return binarysearch(num, l, mp - 1, search_num);
        }
    }

    return -1;
}

int main()
{
    int size_arr, search_num;
    printf("Enter Size Of Array:\n");
    scanf("%d", &size_arr);
    int num[size_arr];
    int l = 0, r = size_arr - 1;
    int i;
    for (i = 0; i < size_arr; i++)
    {
        printf("Enter Value of num %d: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("Write the value of searching: \n");
    scanf("%d", &search_num);
    int index = binarysearch(num, l, r, search_num);
    if (index == -1){
        printf("Number Not Found\n");
    }
    else{
    printf("Searched Value = %d\nFounded At Index %d", search_num, index);
    }
}
