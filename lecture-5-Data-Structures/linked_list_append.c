// Append (end) numbers to a linked list

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
    // i stats at 1 because we need argv[1]; argv[0] is name of program
    for (int i = 1; i < argc; i++)
    {
        // convert string to integer using atoi
        int number = atoi(argv[i]);

        // allocate node for number with malloc
        node *n = malloc(sizeof(node));
        // check if NULL? exit code 1
        if (n == NULL) return 1;

        // point n -> number; next -> NULL
        n -> number = number;
        n -> next = NULL;

        // HOW TO APPEND TO END OF LINKED LIST?
        // check if list is empty
        if (list == NULL)
        {
            // set list to "n"
            list = n;
        }
        // else list has numbers already
        else
        {
            // iterate over nodes in list
            for (node *ptr = list; ptr != NULL; ptr = ptr -> next)
            {
                // if at end of list
                if (ptr -> next == NULL)
                {
                    // append node
                    ptr -> next = n;
                    break;
                }
            }
        }
    }

    // print numbers
    for (node *ptr = list; ptr != NULL; ptr = ptr -> next)
    {
        printf("%i\n", ptr -> number);
    }

    // free memory
    node *ptr = list;
    while (ptr != NULL)
    {
        node *next = ptr -> next;
        free(ptr);
        ptr = next;
    }
}