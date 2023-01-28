#include <cs50.h>
#include <stdio.h>

// call helper function
int get_height(void);
void print_grid(int size);

// MAIN FUNCTION
int main(void)
{
    int n = get_height();
    print_grid(n);
}

// Helper function
int get_height(void)
{
    // initialize int height
    int height;
    // do... while loop in case height < 1 || > 8
    do
    {
        height = get_int("Height: ");
    }
    while (height < 1 || height > 8);
    return height;
}

// Helper function
void print_grid(int size)
{
    // nested for loop
    for (int i = 0; i < size; i++)
    {
        // nested for loop to make pyramid face to right side
        for (int j = i + 1; j < size; j++)
        {
            // print space
            printf(" ");
        }
        // nested for loop for actual pyramid
        for (int hash = size + i + 1; hash > size; hash--)
        {
            // print #
            printf("#");
        }
        // print in new line
        printf("\n");
    }
}

// test: $ check50 cs50/problems/2023/x/mario/less
// style: $ style50 mario.c
// submit: $ submit50 cs50/problems/2023/x/mario/less