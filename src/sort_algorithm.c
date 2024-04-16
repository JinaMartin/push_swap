#include "../push_swap.h"

void    bubble_sort(int *arr, int n)
{
    int tmp;
    int i;
    int j;

    i = 0;
    while (i < n - 1)
    {
        j = 0;
        while (j < n - i - 1)
        {
            if (arr[j] > arr[j + 1])
            {
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}
