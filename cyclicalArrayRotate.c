#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
 
void rotate(int arr[], int size, int r)
    {
    int i = 0, j = 0;
    int tmp = 0;

#if 0 /* for size complexity of 1 */
    for (i = 0; i < r; i++)
        {
        for (j = 0; j < size - 1; j++)
            {
            tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
            }
        }
#endif

    int * tarr = (int* ) malloc (sizeof(int) * size);
    memset (tarr, 0, size);

    //printf ("Rotating: \n");
    for (i = 0; i < r; i++ )
        {
        tarr[size-r+i] = arr [i];
        //printf ("%d:%d ", size-i-1, tarr[size-i-1]);
        }
    //printf ("\n\n");
    
#if 0
    printf ("Rotated: \n");
    for (i = 0; i < size; i++)
        printf ("%d ", tarr [i]);
    printf ("\n");
#endif
    for (j=0; j < size - r; j++)
        tarr[j] = arr[j+r];

#if 0
    printf ("Final: \n");
    for (i = 0; i < size; i++)
        printf ("%d ", tarr [i]);
    printf ("\n");
#endif
    for (i = 0; i < size; i++)
        arr[i] = tarr [i];

    return;
    }

int main (int argc, char* argv[])
    { 
    int testNum = 0;
    int * arr = NULL;
    int n = 5;
    int r = 0;
    int i = 0, j = 0;

   // printf ("Enter number of testcases: \n");
    scanf ("%d", &testNum);

    for (j = 0; j < testNum; j++)
        {
        //printf ("Enter number of elements and rotations (in that order): \n");
        scanf ("%d %d", &n, &r);

        if (n <=0 )
            {
            printf ("Please enter number greater than 0 \n");
            exit (1);
            }

        arr = (int *) malloc (n*sizeof(int));
        if (!arr)
            {
            printf("mem alloc failed \n");
            return -1;
            }

        //printf ("Enter the numbers\n");
        for ( i = 0; i < n; i++ )
            scanf("%d", arr + i);

#if 0
        printf ("Entered numbers are: \n");
        for ( i = 0; i < n; i++ )
            printf("%d ", arr[i]);
        printf ("\n");
#endif

        rotate(arr, n, r);

        //printf ("Entered numbers after rotation are: \n");
        for ( i = 0; i < n; i++ )
            printf("%d ", arr[i]);
        printf ("\n");

        free (arr);
        arr = NULL;
        }
    return 0;
    }

