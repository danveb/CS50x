// Prepend (beginning) numbers to a linked list

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

// struct Node
typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[])
{
    // initialize a linked list with size 0
    node *list = NULL;

    // iterate over command-line argument
    // i starts at 1 because we need argv[1]; argv[0] is name of program
    for (int i = 1; i < argc; i++)
    {
        // convert string to integer using "atoi"
        int number = atoi(argv[i]);

        // Allocate node for number with "malloc"
        node *n = malloc(sizeof(node));
        // check if NULL
        if (n == NULL)
        {
            // exit code 1
            return 1;
        }
        // point n -> number; next -> NULL
        n -> number = number;
        n -> next = NULL;

        // prepend node so it points to existing list
        n -> next = list;
        // update existing list to point to "n"
        list = n;
    }

    // Iterate over a linked list?
    // - we define a tmp variable to point at first node of the linked list
    // - we set first node to second node
    node *ptr = list;
    while (ptr != NULL)
    {
        // print values and continue moving to next value
        printf("%i\n", ptr -> number);
        ptr = ptr -> next;
    }

    // Free memory
    ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr -> next;
        free(ptr);
        ptr = next;
    }
}