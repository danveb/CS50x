// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
// iterate through input string; per each character in string we need to find at least 1 uppercase, 1 lowercase, 1 number and 1 symbol
bool valid(string password)
{
    // initialize cheks for lower/upper/number/symbol
    bool checkLower = false;
    bool checkUpper = false;
    bool checkNumber = false;
    bool checkSymbol = false;

    // iterate over input string
    for (int i = 0; i < strlen(password); i++)
    {
        // initialize current character
        char c = password[i];
        // check: if current character is lowercase?
        if (islower(c))
        {
            checkLower = true;
        }
        // check: if current character is uppercase?
        if (isupper(c))
        {
            checkUpper = true;
        }
        // check: if current character is number?
        if (isdigit(c))
        {
            checkNumber = true;
        }
        // check: if current character is alphanum?
        if (!isalnum(c))
        {
            checkSymbol = true;
        }
        // boolean check for all true's
        if (checkLower && checkUpper && checkNumber && checkSymbol) return true;
    }
    return false;
}

// test -> $ check50 cs50/labs/2023/x/password
// style -> $ style50 password.c