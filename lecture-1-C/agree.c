#include <stdio.h>
#include <cs50.h>

int main(void)
{
    char c = get_char("Do you agree ");
    if(c == 'y' || c == 'Y') // using single quotes for a character
    {
        printf("Agreed\n");
    }
    else if(c == 'n' || c == 'N')
    {
        printf("Not agreed.\n");
    }
    else
    {
        printf("Please stick to just a single character y/n\n"); 
    }
}