#include <stdio.h>
#include <stdlib.h>

void swap (int *a, int *b)
    {
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
    return;
    }

int main()
    {
    int arr [10] = {0};
    int i = 0, j = 0;
    int small = 0;

    printf ("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 10; i++)
        {
        small = i;
        /* 
         * Find the smallest number in each iteration and swap it with the first
         * element of subarray
         */
        for (j = i; j < 10; j++)
            {
            if (arr[j] < arr[small])
                small = j;
            }
        swap (&arr[i], &arr[small]);
        }

    for (i = 0; i < 10; i++)
        printf ("%d ", arr[i]);
    printf ("\n");

    return 0;
    }
