#include <stdio.h>
#include <stdlib.h>

int main ()
    {
    int t = 0;
    int x = 0;
    int bit = 0;
    int i = 0;

    scanf ("%d", &t);

    for (i = 0; i < t; i++)
        {
        scanf("%d", &x);
        scanf("%d", &bit);
        x = (x | (1<<bit));
        printf ("%d\n", x);        
        }
    return 0;
    }
