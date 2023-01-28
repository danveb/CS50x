#include <stdio.h>
#include <cs50.h>

// call helper functions as there's functions below main
int get_size(void);
void print_grid(int size);

int main(void)
{
    // printf("????\n");
    // ????
    // for(int i = 0; i < 4; i++)
    // {
    //     printf("?");
    // }
    // printf("\n");

    // #
    // #
    // #
    // for(int i = 0; i < 3; i++)
    // {
    //     printf("#\n");
    // }

    // ###
    // ###
    // ###
    // for(int i = 0; i < 3; i++)
    // {
    //     for(int j = 0; j < 3; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // ###
    // ###
    // ###
    // const int n = 3; // constant integer starts at 3
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // Ask user for input
    // int n = get_int("Size: ");
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // Ask user for input v2
    // int n = get_int("Size: ");
    // while(n < 1)
    // {
    //     n = get_int("Size: ");
    // }
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // Ask user for input v3 (do while loop)
    // int n;
    // do
    // {
    //     n = get_int("Size: ");
    // }
    // while (n < 1);
    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < n; j++)
    //     {
    //         printf("#");
    //     }
    //     printf("\n");
    // }

    // Write pseudocode
    // Get size of grid
    int n = get_size();
    // Print grid of bricks
    print_grid(n);
}

// Helper function that returns an integer (doesn't take any params)
int get_size(void)
{
    int n;
    do
    {
        n = get_int("Size: ");
    }
    while(n < 1);
    return n;
}

// Helper function print_grid that doesn't have an output (void) but takes an argument
void print_grid(int size)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}