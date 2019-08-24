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

int main ()
    {
    int arr [10] = {0};
    int i = 0, j = 0;

    printf ("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);

    for (i = 0; i < 9; i++)
        for (j = 0; j < 9; j++)
            {
            if (arr[j] > arr[j+1])
                swap(&arr[j], &arr[j+1]);            
            }


    for (i = 0; i < 10; i++)
        printf ("%d ", arr[i]);
    printf ("\n");
    return 0;
    }
