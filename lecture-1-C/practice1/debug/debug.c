// Become familiar wih C syntax
// Learn to debug buggy code

// #include <cs50.h>

// int main(void)
// {
//     // Ask for your name and where live
//     name = get_string("What is your name? ")
//     location = get_string("Where do you live? ")

//     // Say hello
//     print("Hello, %i, from %i!", name, location)
// }

/* DEBUGGED */
#include <stdio.h>
#include <cs50.h>
int main(void)
{
    // Ask for your name and where the user lives
    string name = get_string("What is your name? ");
    string location = get_string("Where do you live? ");
    // Say hello
    printf("Hello, %s, from %s!\n", name, location);
}

// test: $ check50 cs50/labs/2023/x/debug
// style: $ style50 debug.c
// submit: $ N/A