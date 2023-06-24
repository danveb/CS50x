// Implements a list of numbers with an array of fixed size

#include <stdio.h>
#include <stdlib.h>

// int main(void)
// {
//     // declare array list of size 3
//     int list[3];
//     list[0] = 1;
//     list[1] = 2;
//     list[2] = 3;
//     // print the list
//     for (int i = 0; i < sizeof(list)/sizeof(int); i++)
//     {
//         printf("%i\n", list[i]); // 1 2 3
//     }
// }

// int main(void)
// {
//     // allocate memory for a new list
//     int *list = malloc(3 * sizeof(int)); // sizeof int is always 4bytes
//     list[0] = 1;
//     list[1] = 2;
//     list[2] = 3;

//     // check for errors in list
//     if (list == NULL) return 1;

//     // print the list
//     for (int i = 0; i < 3; i++)
//     {
//         printf("%i\n", list[i]); // 1 2 3
//     }
// }

int main(void)
{
    // allocate memory for a new list
    int *list = malloc(3 * sizeof(int)); // sizeof int is always 4bytes
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ... if we needed more memory for the list?
    int *tmp = malloc(4 * sizeof(int));
    // check for errors in tmp
    if (tmp == NULL)
    {
        // freeing memory from list
        free(list);
        return 1;
    }

    // iterate over list array (original)
    for (int i = 0; i < 3; i++)
    {
        // set tmp[i] and copy from list[i]
        tmp[i] = list[i];
    }
    // set tmp[3] equal to 4
    tmp[3] = 4;

    // free list of size 3
    free(list);

    // remember list to new size of 4
    list = tmp;

    // print the list (now size 4)
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]); // 1 2 3 4
    }

    // free newest list and exit
    free(list);
    return 0;
}

/* We can simplify malloc -> realloc
- reallocating memory(original memory, desired memory size)
- automatically frees up old memory and creates new memory
- it is possible to use "realloc" to get fewer memory than originally needed
- "realloc" will be useful for "QUEUE" OR "STACK"; as amount of data grows "realloc" could be used to grow or shink the STACK OR QUEUE

*/

int main(void)
{
    // allocate memory for a new list
    int *list = malloc(3 * sizeof(int));
    list[0] = 1;
    list[1] = 2;
    list[2] = 3;

    // ... we want more memory -> use realloc
    int *tmp = realloc(list, 4 * sizeof(int));
    // check for errors in tmp
    if (tmp == NULL)
    {
        free(list);
        return 1;
    }

    // remember "tmp" is "list"
    list = tmp;

    // set new integer
    list[3] = 4;

    // print the list (size 4)
    for (int i = 0; i < 4; i++)
    {
        printf("%i\n", list[i]);
    }

    // free newest list and exit
    free(list);
    return 0;
}

