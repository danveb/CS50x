// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

// program must accept a single command-line argument, which is the word to convert
// if program is executed without a command-line argument or with more than 1 command-line argument, program will print an error message of choice and return exit status 1 immediately

// program must contain function "replace" that takes a string input and returns a string output
// function will change vowels to numbers
// - a -> 6
// - e -> 3
// - i -> 1
// - o -> 0
// - u -> NO CHANGE
// input parameter for "replace" function will be argv[1] and return value is converted word
// main function will print converted word followed by empty space (printf("\n"))

// function prototype
string replace(string input);

int main(int argc, string argv[])
{
    // check: if argc NOT 2? we throw exit code 1
    if (argc != 2)
    {
        printf("Wrong command-line arguments\n");
        return 1;
    }
    // initialize word as argv[1] and call replace(word) on new variable result
    string word = argv[1];
    string result = replace(word);
    // print result
    printf("%s\n", result);
}

string replace(string input)
{
    string output = input;
    // iterate through the input until end
    for (int i = 0; i < strlen(input); i++)
    {
        // convert character to lowercase
        char c = tolower(input[i]);
        // printf("%c\n", input[i]);

        // switch statement for cases
        // a -> 6
        // e -> 3
        // i -> 1
        // o -> 0
        // default case: just output the character
        switch (c)
        {
            case 'a':
                output[i] = '6';
                break;
            case 'e':
                output[i] = '3';
                break;
            case 'i':
                output[i] = '1';
                break;
            case 'o':
                output[i] = '0';
                break;
            default:
                output[i] = input[i];
                break;
        }
    }
    return output;
}

// test -> $ check50 cs50/labs/2023/x/no-vowels
// style -> $ style50 no-vowels.c