#include <stdio.h>

int main(void) 
{
    printf("hello, world\n");
}

// How to compile a C program? 
// $ make hello -> this compiles binary "source code" into "machine code"
// $ ./hello -> prints C program

// \n is an "escape sequence" (new line) but when managing the terminal we'd have a $ right after the code

// #include <stdio.h> -> header file that imports standard-input/output library to print a specific piece of code. this informs the compiler that we are going to use "printf" functionality to print out code to screen