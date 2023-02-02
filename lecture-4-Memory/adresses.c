#include <stdio.h>
// #include <cs50.h> // use string keyword, but if we delete it we use char *

// int main(void)
// {
//     int n = 50;
//     // printf("%i\n", n); // 50 -> value of 50 stored in memory
//     printf("%p\n", &n); // 0x7ffc3ca741cc -> address of the location of 50 in memory
// }

/*

C provides 2 powerful operators related to memory:
- & Provides the address of something stored in memory
- * Instructs the compiler to go to a location in memory

- %p allows us to view the address of a location in memory
- &n is the address of "n"

Pointers
- a pointer is a variable that contains the address of some value; a pointer is an address in our computer's memory

*/

// int main(void)
// {
//     int n = 50;
//     int *p = &n; // p is a pointer that contains a number that is the address of integer "n"
//     // use format code %p to print out the integer at location "p"
//     printf("%p\n", p); // 0x7ffe6abf4d0c
//     printf("%i\n", *p); // 50
// }

/*

String
- an array of characters stored in memory
- string is the address of a single character
- <cs50.h> library comes with string keyword, but we can delete it and use char * for defining strings

string s = "HI!";
-> H I ! \0

*/

// int main(void)
// {
//     string s = "HI!";
//     // printf("%s\n", s); // HI!
//     printf("%p\n", s); // 0x564429499004
// }

// int main(void)
// {
//     char *s = "HI!";
//     // printf("%p\n", s); // 0x5637030d7004 - we use pointer formatcode
//     // printf("%s\n", s); // HI!
//     printf("%p\n", &s[0]); // 0x564ab8588004
//     printf("%p\n", &s[1]); // 0x564ab8588005
//     printf("%p\n", &s[2]); // 0x564ab8588006
//     printf("%p\n", &s[3]); // 0x564ab8588007
// }

// int main(void)
// {
//     char *s = "HI!";
//     printf("%c\n", s[0]); // H
//     printf("%c\n", s[1]); // I
//     printf("%c\n", s[2]); // !
//     printf("%c\n", s[3]); // (null or \0)
// }

/* Pointer Arithmetic */

// int main(void)
// {
//     char *s = "HI!";
//     // go to address of first character of s
//     printf("%c\n", *s); // H
//     // go to address of second character of s
//     printf("%c\n", *(s+1)); // I
//     // go to address of third character of s
//     printf("%c\n", *(s+2)); // !
// }

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s); // HI!
    printf("%s\n", s+1); // I
    printf("%s\n", s+2); // !
}