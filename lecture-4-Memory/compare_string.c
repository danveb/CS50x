#include <stdio.h>
#include <cs50.h>
#include <string.h>

// int main(void)
// {
//     // Get two strings
//     char *s = get_string("s: ");
//     char *t = get_string("t: ");

//     // check: if string s == string t?
//     // if (s == t) // WRONG!!!!!!!!!!! we're comparing memory addresses here
//     if (strcmp(s, t) == 0) // CORRECT WAY BECAUSE OF STRCMP method
//     {
//         printf("Same\n");
//     }
//     else
//     {
//         printf("Different\n");
//     }
// }

int main(void)
{
    // Get two strings
    char *s = get_string("s: ");
    char *t = get_string("t: ");
    // Print addresses (%p) of both strings
    printf("%p\n", s); // 0x5565568f96b0 -> b0 here
    printf("%p\n", t); // 0x5565568f96f0 -> f0 here so difference
}