#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // command-line arguments taking an integer and string
// argc -> argument count (length of array)
// argv -> array
{
    // string name = get_string("What's your name? ");
    // printf("Hello %s\n", name);

    // printf("Hello, %s\n", argv[1]);
    // ./greet Danny
    // Hello, Danny

    // printf("Hello, %s %s\n", argv[1], argv[2]);
    // ./greet Danny Bae
    // Hello, Danny Bae

    if (argc == 2)
    {
        printf("hello, %s\n", argv[1]);
    }
    else
    {
        printf("hello world");
    }
}

/*

MAIN WAY TO DEFINE A "MAIN" FUNCTION?
1. #include <stdio.h>
int main(void)
{
    ...
}

2. #include <stdio.h>
int main(int argc, string argv[])
{
    ...
}

*/