#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct treeNode {
    struct treeNode * left;
    struct treeNode * right;
    int data;
} NODE;

NODE * createNode(int data)
    {
    NODE * newNode = (NODE *) malloc (sizeof(NODE));
    if (newNode)
        {
        newNode->left = newNode->right = NULL;
        newNode->data = data;
        }
    return newNode;
    }

NODE * insertData(NODE * root, int data)
    {
    if (root == NULL)
        {
        root = createNode (data);
        }
    else if (root->data > data)
        {
        root->left = insertData(root->left, data);
        }
    else
        root->right = insertData(root->right, data);

    return root;
    }

void print(NODE * root)
    {
    if (root)
        printf ("%d\n", root->right->data);
    return;
    }
int printData(NODE * root)
    {
    if(root)
        {
        printf ("%d \n", root->data);
        if(root->left)
            printData((root->left));
        if(root->right)
            printData((root->right));
        }
    return 0;
    }

/* In Order: Left - Root- Right */
void printInOrder (NODE * root)
    {
    if (root)
        {
        if (root->left)
            printInOrder(root->left);
        printf ("%d ", root->data);
        if (root->right)
            printInOrder (root->right);
        }
    return;
    }

/* Pre Order: Root - Left - Right */
void printPreOrder (NODE * root)
    {
    if (root)
        {
        printf ("%d ", root->data);
        if (root->left)
            printInOrder(root->left);
        if (root->right)
            printInOrder (root->right);
        }
    return;
    }

/* Post Order: Left - Right - Root */
void printPostOrder (NODE * root)
    {
    if (root)
        {
        if (root->left)
            printInOrder(root->left);
        if (root->right)
            printInOrder (root->right);
        printf ("%d ", root->data);
        }
    return;
    }

int treeSize(NODE * root)
    {
    int size = 0;

    if (root)
        {
        if (root->left)
            size = size + treeSize(root->left);
        if (root->right)
            size = size + treeSize(root->right);
        size = size + 1;
        }
    else
        return 0;

    return size;
    }
int main()
    {
    char * num = malloc (4 * sizeof(char)) ; 
    NODE * root = NULL;

    printf ("Enter the numbers to be stored. Press q once youo are done\n");

    while (true)
        {
        scanf ("%s", num);
        if (!strcmp(num, "q"))
            break;
        root = insertData(root, atoi(num));
        }

    printf ("Entered Values are \n ====================================\n");
    print(root);
    printData (root);
    printf ("In Order: \n");
    printInOrder(root);
    printf ("\n\n");
    printf ("Pre Order: \n");
    printPreOrder(root);
    printf ("\n\n");
    printf ("Post Order: \n");
    printPostOrder(root);
    printf ("\n\n");

    printf ("Size: %d\n", treeSize(root));
    return 0;
    }

