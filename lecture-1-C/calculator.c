#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // integer
    // int x = get_int("x: ");
    // int y = get_int("y: ");
    // printf("%i\n", x + y);

    // long
    // long x = get_long("x: ");
    // long y = get_long("y: ");
    // calculate "li" (long)
    // printf("%li\n", x + y);

    // float -> decimal
    // long x = get_long("x: ");
    // long y = get_long("y: ");
    // float z = (float) x / (float) y;
    // // calculate "f" (float)
    // printf("%.3f\n", z);

    // double -> more precision to float (double memory 64bits)
    long x = get_long("x: ");
    long y = get_long("y: ");
    double z = (double) x / (double) y;
    // calculate "f" (float)
    printf("%.20f\n", z);
}

// Computers have a limit on memory so we end up with integer overflow
// 32bits for C
// int has a very low limit of bits; best to use "long" for more memory