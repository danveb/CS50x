#include <cs50.h>
#include <stdio.h>

// prototype of get_negative_int function
int get_negative_int(void);

int main(void)
{
    int i = get_negative_int();
    printf("%i\n", i);
}

// helper function
int get_negative_int(void)
{
    int n; // need to specify data type for a variable due to scope to use "n" variable outside curly braces
    do
    {
        n = get_int("Negative Integer: ");
    }
    while (n >= 0); // do... while loop keeps running infinitely if n >= 0 and doesn't step into "return"; if we use a negative integer then we'll be able to correctly return a negative integer
    return n;
}