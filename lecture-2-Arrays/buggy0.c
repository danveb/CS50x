#include <stdio.h>

int main(void)
{
    for (int i = 0; i < 3; i++)
    {
        // printf("i is %i\n", i); // # # #
        printf("#\n");
    }
}

/* How to debug?
1. printf
- easiest to use since we can print out what the code looks like

2. debugger
- VSCode already bakes in "debugger"
- first need to compile and run "debug50", a custom command for CS50x

$ make buggy0
$ debug50 ./buggy0

- step over: runs over piece of code
- step into: runs code line by line

3. rubber duck debugging
- process where a developer speaks out loud the code to talk about the code problem. This way it's easier to find a potential bug in the code

*/