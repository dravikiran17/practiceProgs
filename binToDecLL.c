#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node * next;
}NODE;

int listInsert(NODE ** head, int input)
    {
    NODE * temp = (NODE *) malloc (sizeof(NODE));
            printf ("%s:%d input: %d \n", __FUNCTION__, __LINE__, input);
    if (!temp)
        {
        printf ("%s:%d mem alloc failed in Insert operation\n", __FUNCTION__, __LINE__);
        return -1;
        }
    temp->data = input;
    temp->next = (*head);
    *head = temp;

    return 0;
    }

void printList(NODE * head)
    {
    NODE * temp = head;
    while (temp->next != NULL)
        {
        printf ("data: %d\n", temp->data);
        temp = temp->next;
        }
    return;
    }

int todec(NODE * head)
    {
    NODE * temp = head;
    int num = 0;
    int i = 0;
    while (temp->next != NULL)
        {
        if (temp->data)
            num = num | (1 << i);
        temp = temp->next;
        i++;
        }
    return num;
    }

int main()
    {
    int i = 0;
    int d = 0;
    int input;
    int status = -1;
    int m = 1000000007;
    int t = 0;
    int j = 0;
    int n = 0; /* number of bits */

    scanf ("%d", &t);

    while (j < t)
        {
        i = 0;
        NODE * listHead = (NODE *) malloc (sizeof(NODE));
        if (!listHead)
            {
            printf("%s:%d memalloc for listHead Failed\n", __FUNCTION__, __LINE__);
            return -1;
            }
        listHead->next = NULL;

        // printf ("Enter the number in bin format: \n");

        scanf ("%d", &n);
        while (i < n)
            {
            printf ("%s:%d \n", __FUNCTION__, __LINE__);
            scanf ("%d\n", &input);
            printf ("%s:%d \n", __FUNCTION__, __LINE__);
            status = listInsert (&listHead, input);
            printf ("%s:%d \n", __FUNCTION__, __LINE__);
            if (status != 0)
                {
                printf ("%s:%d List Insert for %d failed\n", __FUNCTION__, __LINE__, input);
                return -1;
                }
            printf ("%s:%d \n", __FUNCTION__, __LINE__);
            i++;
            printf ("%s:%d \n", __FUNCTION__, __LINE__);
            printf ("bit num: %d\n", i);
            }

#if 0
        printf ("Entered: \n");
        printList(listHead);
        printf("\n");
#endif
        printf ("num: %d\n", (todec(listHead))%m);
        j++;
        }
    return 0;
    }
