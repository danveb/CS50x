#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int start_size;
    do
    {
        start_size = get_int("Enter start size: ");
    }
    while (start_size < 9);
    // TODO: Prompt for end size
    int end_size;
    do
    {
        end_size = get_int("Enter end size: ");
    }
    while (end_size < start_size);
    // TODO: Calculate number of years until we reach threshold
    int years = 0;
    while (start_size < end_size)
    {
        start_size = start_size + (start_size / 3) - (start_size / 4);
        years += 1;
    }
    // TODO: Print number of years
    printf("Years: %i", years);
}

// test: $ check50 cs50/labs/2023/x/population
// style: $ style50 population.c
// submit: $ submit50 cs50/labs/2023/x/population