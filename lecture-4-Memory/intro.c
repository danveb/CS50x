/* Memory

Hexadecimal
- system of counting that has 16 counting values -> 0 1 2 3 4 5 6 7 8 9 a b c d e f
- known as base-16
- useful because hexadecimal maps nicely to 4bits

When counting in hexadecimal, each column is a power of 16.
The number 0 is represented as 00.
The number 1 is represented as 01.
The number 9 is represented by 09.
The number 10 is represented as 0A.
The number 15 is represented as 0F.
The number 16 is represented as 10.
The number 255 is represented as FF, because 16 x 15 (or F) is 240. Add 15 more to make 255. This is the highest number you can count using a two-digit hexadecimal system.

C provides 2 powerful operators related to memory:
- & Provides the address of something stored in memory
- * Instructs the compiler to go to a location in memory

- %p allows us to view the address of a location in memory
- &n is the address of "n"

Pointers
- a pointer is a variable that contains the address of some value; a pointer is an address in our computer's memory

String
- an array of characters stored in memory
- string is the address of a single character
- <cs50.h> library comes with string keyword, but we can delete it and use char * for defining strings

string s = "HI!";
-> H I ! \0

int main(void)
{
    char *s = "HI!";
    // printf("%p\n", s); // 0x5637030d7004 - we use pointer formatcode
    // printf("%s\n", s); // HI!
    printf("%p\n", &s[0]); // 0x564ab8588004
    printf("%p\n", &s[1]); // 0x564ab8588005
    printf("%p\n", &s[2]); // 0x564ab8588006
    printf("%p\n", &s[3]); // 0x564ab8588007
}

int main(void)
{
    char *s = "HI!";
    printf("%c\n", s[0]); // H
    printf("%c\n", s[1]); // I
    printf("%c\n", s[2]); // !
    printf("%c\n", s[3]); // (null or \0)
}

Pointer Arithmetic

int main(void)
{
    char *s = "HI!";
    // go to address of first character of s
    printf("%c\n", *s); // H
    // go to address of second character of s
    printf("%c\n", *(s+1)); // I
    // go to address of third character of s
    printf("%c\n", *(s+2)); // !
}

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s); // HI!
    printf("%s\n", s+1); // I
    printf("%s\n", s+2); // !
}

Comparing Strings?
- a string of characters is an array of characters identified by its first byte
- we can't compare two strings with == operator because it compares memory addresses instead of characters... so we use "strcmp" method from <string.h> header file

#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");

    // check: if string s == string t?
    // if (s == t) // WRONG!!!!!!!!!!! we're comparing memory addresses here
    if (strcmp(s, t) == 0) // CORRECT WAY BECAUSE OF STRCMP method
    {
        printf("Same\n");
    }
    else
    {
        printf("Different\n");
    }
}

Copying Strings?
- when we copy a string in C it copies the literal address of where the variable lives in memory
-- unlike JavaScript or Python, when we copy a string it copies its value

char *s = "Hello";
char *t = s;

To make an authentic copy of the string:
- "malloc" - allocats a block of specific size of memory (memory allocation) -> returns NULL
- "free" - allows to tell compiler to free up the previously allocated memory

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

Valgrind
- tool to check if there are memory-related issues with programs that utilize "malloc"
- it specifically checks to see all memory is "free" after allocation

$ valgrind ./memory

Garbage Values
- when asking compiler for a block of memory, there's no guarantee the memory will be empty
- it's very possible allocated was previously utilized by the computer; we may see junk or garbage values
- always initialize variables to "something"

Swap
- whenever we want to swap 2 values we need a temporary variable
- above code will not work because variables x, y are copied by a, b by values only...
- scope: context in where the variable exists (typically within curly braces)
- in order to solve swap we need to manage the "address" by using *

#include <stdio.h>

void swap(int *a, int *b);

int main(void)
{
    int x = 1;
    int y = 2;
    printf("x is %i, y is %i\n", x, y);
    swap(&x, &y); // need to use & for "addresses"
    printf("x is %i, y is %i\n", x, y);
}

// swap works by passing 2 addresses "a", "b" (NOT VALUES, just addresses)
void swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

Overflow
- a "heap" overflow is when we overflow the heap, touching areas of memory we're not supposed to.
- a "stack" overflow is when too many functions are called, overflowing the amount of memory available
- both are called "buffer overflows"

"scanf"
- scan user keyboard for an input
- works on int and char (strings); however, code is slightly different

#include <stdio.h>

int main(void)
{
    // initialize int x variable
    int x;
    printf("x: "); // 50
    scanf("%i", &x); // scans user keyboard for input, specifically int this time
    printf("x: %i\n", x); // 50
}


#include <stdio.h>

int main(void)
{
    // initialize string as char * that points to character
    // initialize array of size 4 to allocate memory
    char s[4];
    printf("s: ");
    scanf("%s", s); // we don't need &s -> because s is already an address
    printf("s: %s\n", s);
}

*/