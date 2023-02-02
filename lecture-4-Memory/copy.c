// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
//     // Get a string
//     char *s = get_string("s: ");

//     // copy string address (not like JS/python that it copies value)
//     char *t = s;

//     // capitalize first letter in string "t"
//     t[0] = toupper(t[0]);

//     // print string twice
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }

// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <ctype.h>

// int main(void)
// {
//     // Get a string
//     char *s = get_string("s: ");

//     // copy string address (not like JS/python that it copies value)
//     char *t = s;

//     // capitalize first letter in string "t"
//     if (strlen(t) > 0)
//     {
//         t[0] = toupper(t[0]);
//     }

//     // print string twice
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }

/* Copying Strings?
- when we copy a string in C it copies the literal address of where the variable lives in memory
-- unlike JavaScript or Python, when we copy a string it copies its value

char *s = "Hello";
char *t = s;

To make an authentic copy of the string:
- "malloc" - allocats a block of specific size of memory (memory allocation) -> returns NULL
- "free" - allows to tell compiler to free up the previously allocated memory

*/

// #include <stdio.h>
// #include <cs50.h>
// #include <string.h>
// #include <ctype.h>
// #include <stdlib.h> // malloc & free in header file

// int main(void)
// {
//     // Get a string
//     char *s = get_string("s: ");

//     // allocate memory for another string
//     char *t = malloc(strlen(s) + 1); // malloc will allocate memory based on length of string + '\0' null character

//     // copy string into memory, including '\0' null character
//     // not efficient to be looping over length of string + 1 ...
//     for (int i = 0; i < strlen(s) + 1; i++)
//     {
//         // copy each character from s to t
//         t[i] = s[i];
//     }

//     // check: if length of "t" is > 0 we can capitalize copy for "t"
//     if (strlen(t) > 0)
//     {
//         t[0] = toupper(t[0]);
//     }

//     // print strings
//     printf("s: %s\n", s);
//     printf("t: %s\n", t);
// }

/* OPTIMIZED FOR COPYING A STRING */

#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // Get a string
    char *s = get_string("s: "); // hello

    // edge case: if string is NULL? we can return 0
    if (s == NULL) return 1;

    // Allocate memory for another string
    char *t = malloc(strlen(s) + 1); // includes + 1 for '\0'

    // edge case: if string is NULL? we can return 0
    if (t == NULL) return 1;

    // copy string into memory
    strcpy(t, s); // 't' will copy 's' string

    // check: if t has a length > 0 we will uppercase first letter of 't'
    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    // print results
    printf("s: %s\n", s); // hello
    printf("t: %s\n", t); // Hello

    // ** when allocating memory with malloc we must explicitly free memory
    free(t);
    // explicitly return 0 to make sure program exits correctly
    return 0;

}