#include <cs50.h> // imports cs50.h library
#include <stdio.h> // imports stdio.h library for printf function

int main(void)
{
    // string answer = get_string("What's your name? "); // we explicitly declare "string" answer as variable when creating; when updating we don't
    // printf("hello, %s\n", answer);

    string first_name = get_string("What's your first name? ");
    string last_name = get_string("What's your last name? ");
    printf("hello, %s %s\n", first_name, last_name);

    printf("I got a 100%%\n");
}

// Compile?
// $ make variable
// $ ./variable

// %s is a format specifier for "string" since we're using strings