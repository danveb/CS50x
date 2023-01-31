#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // char c1 = 'H';
    // char c2 = 'I';
    // char c3 = '!';

    // printf("%c%c%c\n", c1, c2, c3);
    // // Hi!

    // printf("%i %i %i\n", c1, c2, c3);
    // // 72 73 33

    // string s = "Hi!";
    // printf("%s\n", s);
    // Hi!

    // printf("%c %c %c\n", s[0], s[1], s[2]);
    // H i !

    // printf("%i %i %i %i\n", s[0], s[1], s[2], s[3]);
    // 72 105 33 0

    // string s = "HI!";
    // string t = "BYE!";
    // printf("%s\n", s);
    // HI!
    // printf("%s\n", t);
    // BYE!

    // string words[2];
    // words[0] = "HI!";
    // words[1] = "BYE!";
    // printf("%s\n", words[0]);
    // HI!
    // printf("%s\n", words[1]);
    // BYE!

    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";
    printf("%c %c %c\n", words[0][0], words[0][1], words[0][2]);
    // H I !
    printf("%c %c %c %c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
    // B Y E !


}