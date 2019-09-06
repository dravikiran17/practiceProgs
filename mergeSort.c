#include <stdio.h>
#include <stdlib.h>

int iteration = 0;
void merge(int a[], int p, int q, int r)
    {
    int b[10]={0};
    int i,j,k = 0;

    i = p;
    j = q+1;

    while (i <=q && j <= r)
        {
        if (a[i] < a[j])
            {
            b[k++] = a[i++];
            }
        else
            b[k++] = a[j++];
        }

    while (i <=q)
        b[k++] = a[i++];
    while (j <=r)
        b[k++] = a[j++];

    for (i = r; i >= p; i--)
        {
        printf ("Merge: i: %d k: %d val: %d\n", i, k, b[k]);
        a[i] = b[k-1];
        k--;
        }

    return;
    }

void mergesort(int a[], int p, int r)
    {
    int q = 0;
    printf ("iteration: %d\n", iteration);
    iteration++;
    if (p < r)
        {
        q = (p+r)/2;
        mergesort(a, p, q);
        mergesort(a, q+1, r);
        printf ("p: %d, q: %d, r: %d \n", p,q,r);
        merge(a,p,q,r);
        }
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

    mergesort(arr, 0, 9);
    printf ("After sorting: \n");
    for (i = 0; i < 10; i++)
        printf ("%d ", arr[i]);
    printf ("\n");
    return 0;
    }

