#include <cs50.h>
#include <stdio.h>

// int main(int argc, string argv[])
// {
//     if (argc != 2)
//     {
//         printf("Missing command-line argument\n");
//     }
//     else
//     {
//         // prints command-line argument X
//         printf("Hello, %s\n", argv[1]);
//     }
// }

/* Compile?
$ make status
$ ./status
// Missing command-line argument

$ make status
$ ./status David
// Hello, David

Error message?
$ ./status
// Missing command-line argument
$ echo $?
// 0

$ ./status Danny
// Hello, Danny
$ echo $?
// 0

*/

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Missing command-line argument\n");
        // we can return a 1 for explicit 1 when we echo
        return 1;
    }
    else
    {
        // prints command-line argument X
        printf("Hello, %s\n", argv[1]);
        // we can return a 0 for explicit 0 when we echo
        return 0;
    }
}

/* Compile?
$ make status
$ ./status Danny
// Hello, Danny
$ echo $?
// 0

$ make status
$ ./status
// Missing command-line argument
$ echo $?
// 1

*/