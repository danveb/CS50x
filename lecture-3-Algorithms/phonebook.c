#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string names[] = {"Carter", "David"};
    string numbers[] = {"+1-617-495-1000", "+1-949-468-2750"};

    // prompt user for a "name"
    string name = get_string("Name: ");

    // Perform linear search
    // iterate through
    for (int i = 0; i < sizeof(names)/sizeof(string); i++)
    {
        // check: if
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not Found\n");
    return 1;
}