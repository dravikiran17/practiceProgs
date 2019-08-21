#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#if 0 /* string reverse approach */
void reverse(char *s)
{
   int length, c;
   char *begin, *end, temp;
 
   length = strlen(s);
   begin  = s;
   end    = s;
 
   for (c = 0; c < length - 1; c++)
      end++;
 
   for (c = 0; c < length/2; c++)
   {        
      temp   = *end;
      *end   = *begin;
      *begin = temp;
 
      begin++;
      end--;
   }
}

int main ()
    {
    int t = 0;
    int x = 0;
    int i = 0;
    char num[3] = {'\0'};
    char swapped[3] = {'\0'};
    printf ("Enter number of test cases:\n");
    scanf("%d", &t);
    for (i = 0; i < t; i++)
        {
        printf ("Enter the number:\n");
        scanf("%d", &x);
        sprintf(num, "%02x", x);
        reverse(num);
        printf ("%s\n", num);
        }
    return 0;
    }

#endif

/* bit manipulation */
int main ()
    {
    int t = 0;
    int x = 0;
    int i = 0;

    scanf ("%d", &t);

    for (i = 0; i < t; i++)
        {
        scanf ("%d", &x);
        x = ((x >> 4) | (x << 4)) & 0xff;
        printf ("%d\n", x);
        }
    return 0;
    }
