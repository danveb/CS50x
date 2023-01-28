#include <stdio.h>
#include <cs50.h>

int main(void)
{
    string name = get_string("Enter your name: ");
    printf("hello, %s\n", name);
}

// test: $ check50 cs50/problems/2023/x/hello
// style: $ style50 hello.c
// submit: $ submit50 cs50/problems/2023/x/hello