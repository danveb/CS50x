/* Intro to C (Programming Language)

- Machines only understand "machine code" in binary (0 and 1's) whereas humans write "source code", which is a list of instructions for the computer that is human readable.
- we are able to convert "source code" into "machine code" using a "compiler"
- we aim for code correctness, which is NOT buggy code
- we aim for design, which allwos for code to be maintainable, faster
- we aim for style, the aesthetics of code

How to Create and Open a new file?
$ code hello.c -> creates and opens a hello.c file on VSCode

How to Compile?
$ make hello (without .c)
$ ./hello -> this prints content of hello.c

#include <stdio.h> -> header file that imports standard-input/output library to print a specific piece of code. this informs the compiler that we are going to use "printf" functionality to print out code to screen

#include <cs50.h> -> header file that imports cs50 library to use pre-programmed functions

Data Types in C (Primitive)
- bool -> Boolean
- char -> Character - When typing must be in 'single quote'
- double
- float -> Decimal
- int -> Integer
- long
- string -> String
- ...

Linux and Command Line
- Linux is an operating system via the command line in terminal window
- Common command-line code we can use:
-- cd -> change current directory (folder)
-- cp -> copy files and directories
-- ls -> list all files in a directory ** MOST COMMON
-- mkdir -> create a new directory
-- mv -> move (rename) files and directories
-- rm -> remove (delete) files
-- rmdir -> remove (delete) directories

*/