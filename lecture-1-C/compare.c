#include <stdio.h> // imports stdio.h library for printf function
#include <cs50.h> // imports cs50.l library to use get_int function

int main(void)
{
    int x = get_int("What's x? ");
    int y = get_int("What's y? ");
    // Conditional
    if(x < y)
    {
        printf("x is less than y\n");
    }
    else if(x > y)
    {
        printf("x is greater than y\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}