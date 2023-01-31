#include <cs50.h>
// string get_string(string prompt);
#include <stdio.h>
// int printf(string format, ...);

int main(void)
{
    string name = get_string("What's your name? ");
    printf("Hello, %s\n", name);
}

// $ clang -o hello hello.c -lcs50 -> link cs50 to correctly compile and execute our code
// $ ./hello