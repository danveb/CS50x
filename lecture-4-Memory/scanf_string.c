#include <stdio.h>

int main(void)
{
    // initialize string as char * that points to character
    // initialize array of size 4 to allocate memory
    char s[4];
    printf("s: ");
    scanf("%s", s); // we don't need &s -> because s is already an address
    printf("s: %s\n", s);
}