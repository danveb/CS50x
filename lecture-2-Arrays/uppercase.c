#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    string str = get_string("Before: ");
    printf("After: ");
    // for (int i = 0; i < strlen(str); i++)
    // {
    //     // check if character is lowercase?
    //     // if (str[i] >= 'a' && str[i] <= 'z')
    //     if (islower(str[i]))
    //     {
    //         // subtract 32 to convert lowercase to uppercase
    //         // printf("%c", str[i] - 32);
    //         printf("%c", toupper(str[i]));
    //     }
    //     else
    //     {
    //         printf("%c\n", str[i]);
    //     }
    // }

    // just make everything uppercase with a simple line of code
    // {
    //     printf("%c", toupper(str[i]));
    // }

    // option #2 taking into account a cleaner length of the string
    for (int i = 0, n = strlen(str); i < n; i++)
    {
        printf("%c", toupper(str[i]));
    }
    printf("\n");
}