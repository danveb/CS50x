#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

float calc_hours(int hours[], int weeks, char output);

int main(void)
{
    int weeks = get_int("Number of weeks taking CS50: ");
    int hours[weeks];

    for (int i = 0; i < weeks; i++)
    {
        hours[i] = get_int("Week %i HW Hours: ", i);
    }

    char output;
    do
    {
        output = toupper(get_char("Enter T for total hours, A for average hours per week: "));
    }
    while (output != 'T' && output != 'A');

    printf("%.1f hours\n", calc_hours(hours, weeks, output));
}

// TODO: complete the calc_hours function
// total up hours saved in array into new variable
// depending on output, return sum or avg number of hours
float calc_hours(int hours[], int weeks, char output)
{
    // initialize total_hours at 0
    int total_hours = 0;
    // iterate through the weeks
    for (int i = 0; i < weeks; i++)
    {
        // for each hour per week we'll increase to total_hours
        total_hours += hours[i];
    }
    // check: if output is 'T'? we return total_hours
    // else we return average number of hours
    if (output == 'T')
    {
        return (float) total_hours;
    }
    else
    {
        return (float) total_hours / weeks;
    }
}

// check -> $ check50 cs50/labs/2023/x/hours
// style -> style50 hours.c
