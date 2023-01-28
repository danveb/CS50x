#include <stdio.h>
#include <cs50.h> // we can use boolean with <cs50.h> or <stdbool.h>

int main(void)
{
    // Not efficient
    // printf("meow\n");
    // printf("meow\n");
    // printf("meow\n");

    // Efficient -> use loop with variable
    // int counter = 0;
    // counter = counter + 1; // counter += 1; -> syntactic sugar means there are many ways to write same piece of code that do same thing

    // while loop
    // int i = 0;
    // while(i < 3)
    // {
    //     printf("meow\n");
    //     i += 1;
    // }

    // for loop
    // for(int i = 0; i < 3; i++)
    // {
    //     printf("meow\n");
    // }

    // infinite loop
    while(true)
    {
        printf("meow\n");
    }
}