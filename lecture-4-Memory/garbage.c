#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    // initialize scores array with size 1024
    int scores[1024];
    // iterate over size of array
    for (int i = 0; i < 1024; i++)
    {
        printf("%i\n", scores[i]); // will print 1024 values
    }
}

/*

Garbage Values
- when asking compiler for a block of memory, there's no guarantee the memory will be empty
- it's very possible allocated was previously utilized by the computer; we may see junk or garbage values
- always initialize variables to "something"

*/