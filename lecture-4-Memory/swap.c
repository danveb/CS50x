// #include <stdio.h>

// void swap(int a, int b);

// int main(void)
// {
//     int x = 1;
//     int y = 2;
//     printf("x is %i, y is %i\n", x, y);
//     swap(x, y);
//     printf("x is %i, y is %i\n", x, y);
// }

// void swap(int a, int b)
// {
//     int tmp = a;
//     a = b;
//     b = temp;
// }

/*

Swap
- whenever we want to swap 2 values we need a temporary variable
- above code will not work because variables x, y are copied by a, b by values only...
- scope: context in where the variable exists (typically within curly braces)
- in order to solve swap we need to manage the "address" by using *

*/

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