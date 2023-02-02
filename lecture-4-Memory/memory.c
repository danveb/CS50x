#include <stdio.h>
#include <stdlib.h> // related to malloc & free

int main(void)
{
    // initialize int x with memory allocation
    int *x = malloc(3 * sizeof(int));
    x[0] = 72;
    x[1] = 73;
    x[2] = 33;
    // free memory
    free(x);
    return 0;
}

/* Valgrind
- tool to check if there are memory-related issues with programs that utilize "malloc"
- it specifically checks to see all memory is "free" after allocation

$ valgrind ./memory


*/