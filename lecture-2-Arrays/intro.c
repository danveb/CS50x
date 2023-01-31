/* Intro to Arrays

- Encryption is the act of hiding plain text from prying eyes. decrypting, then, is the act of taking an encrypted piece of text and returning it to a human-readable form.

- we use a compiler to turn source code (what we write) into machine code so that our computer can understand

1. First week we learned to compile:
$ make hello
$ ./hello

- Command line arguments
- we use an argument after a command so it alters the behavior of the program

2. Another way to compile into machine code
- $ clang -o hello hello.c
- $ ./hello

3. Neat way to compile into machine code (best when using cs50 library)
- $ clang -o hello hello.c -lcs50 -> link cs50 to correctly compile and execute our code
- $ ./hello

** BEST WAY IS TO KEEP USING 1st week code because it's already baked into cs50 vscode environment
- $ make hello
- $ ./hello

There are 4 steps when it comes to compiling from source code to machine code:

1. preprocessing
- we use a preprocessor (with #) to bring in header files (libraries) to copy/paste everything from the file to our program
- #include <cs50.h> -> string get_string(string prompt);
- #include <stdio.h> -> int printf(string format, ...);

2. compiling
- once a program is preprocessed we are ready to compile
- compiler turns source code and turns it into "assembly language" (still not 0/1's yet!)

3. assembling
- when compiler converts "assembly code" into machine code (binary) as 0/1's for our computer to understand

4.linking
- code from included libraries are converted also into machine code and combined with our code
- final executable file is outputted

** decompiling
- means converting machine code into source code, but downside is easier to exploit/hack code even though it's very difficult/challenging to engineer-it

How to debug?
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

Type Casting
- we explictly tell C that a number is a float
- (float) 3 -> 3.0

Arrays
- a group of variables of same data type (string, int, etc.) into contiguous block of memory
- ex: a shoe rack with shoes on 1st rack, 2nd rack, 3rd rack
- C automatically adds a \0 (nul) at end of array; it takes 1 more byte than what we typed

1. uninitialized array -> dataType name[arraySize];
- array that specifies its size but does not include its values

2. initialized array
-> dataType name[arraySize] = { value1, value2, value3 };
-> dataType name = { value1, value2, value3 };
- we can initialize an array that specifies its size and values OR an array with only its values since size is already supported by its values

int scores[3] = { 72, 73, 33 } -> a group of integer score stored in contiguous memory
scores[0] = 72
scores[1] = 73
scores[2] = 33

Strings
- an "array" of characters stored in memory
- we can get index of each character just like arrays
- C automatically adds a \0 (nul) at end of string; it takes 1 more byte than what we typed

1. uninitialized string as array
-> int array[] = { 'H', 'e', 'l', 'l', 'o' };
-> char comp[] = { 'C', 'o', 'm', 'p', 'u', 't', 'e', 'r', '\0' };

2. string literal
-> char word[] = "Hello World";
-> char compCode[] = "Computer Code";

string s = "Hello World";
s[0] = 'H'
s[1] = 'e'

Get LENGTH of a string?
- use #include <string.h> and strlen(string) method

Iterate through strings
-> easier with for loop so we visit each character

char string1[] = "Hello World";
for (int i = 0; i < strlen(string1); i++) {
    printf("%c\n", string1[i]);
}

Command-line Arguments
- input to a command that alters behavior of the command
- $ gcc hello.c -o hello
- $ ./hello

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

Exit status
- whenever main function exits it returns an exit status to indicate "error"
- similarly 404 status code is error code for NOT FOUND

"int" in main function is for integer that returns a 0 (for success)

$ echo $? -> returns exit code (by default 0 is always as success) unless we decide to return a custom code for 0, 1

Cryptography
- art of encypting (scrambling) information where we run it into an algorithm to encrypt it
- we can decrypt it to get back the message
- turn plaintext (takes a key) -> cipher (algorithm) -> ciphertext

Encryption
- plaintext + key -> cipher (algorithm) -> ciphertext
- we take plaintext and a "KEY" in order to get ciphertext

Decryption
- ciphertext -> ciper (algorithm) -> plaintext + key
- we take ciphertext and key to get plaintext

*/