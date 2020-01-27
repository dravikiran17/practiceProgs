#include <stdio.h>
#include <stdlib.h>

int itr = 0;

void swap (int *a, int *b)
    {
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
    return;
    }

int partition(int a[], int p, int r)
    {
    int pi = 0;
    int pivot = a[r];
    int i = p - 1;
    int j;

    for (j = p; j < r; j++)
        {
        if (a[j] < pivot)
            {
            i++;
            swap(&a[i], &a[j]);
            }
        }
    swap (&a[i+1], &a[r]);
    return (i+1);
    }

void quicksort(int a[], int p, int r)
    {
    int q = 0;
    int pivot = 0;
    int i;

    if (p < r)
        {
        pivot = partition(a, p, r);
        printf ("After patition:\n");
        for (i = 0; i < 10; i++)
            printf ("%d ", a[i]);
        printf ("\n\n");
        quicksort(a, p, pivot-1);
        quicksort(a, pivot+1, r);
        }
    itr++;
    printf ("After iter %d:\n", itr);
    for (i = 0; i < 10; i++)
        printf ("%d ", a[i]);
    printf ("\n\n");
    return;
    }

int main ()
    {
    int arr [10] = {0};
    int i = 0, j = 0;

    printf ("Enter 10 numbers:\n");

    for (i = 0; i < 10; i++)
        scanf("%d", &arr[i]);


    printf ("Before sorting: \n");
    for (i = 0; i < 10; i++)
        printf ("%d ", arr[i]);
    printf ("\n");

    quicksort(arr, 0, 9);
    printf ("After sorting: \n");
    for (i = 0; i < 10; i++)
        printf ("%d ", arr[i]);
    printf ("\n");
    return 0;
    }
