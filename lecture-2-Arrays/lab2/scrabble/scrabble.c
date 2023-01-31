#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet (26 letters total)
// ALPHABET     A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U,  V, W, X, Y, Z
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};
// CODE -> C = 3
//      -> O = 1
//      -> D = 2
//      -> E = 1
//      -> TOTAL = 7

// function prototype for C to correctly compile
int compute_score(string word);

// main function
// program prompts 2 players for a word
int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    // printf("%i\n", score1);
    // printf("%i\n", score2);

    // check: if score1 > score2 ? print Player 1 wins! else Player 2 wins!
    // if score1 == score2 ? print Tie!
    if (score1 > score2)
    {
        printf("Player 1 wins!\n");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}

// compute_score is a function that takes a str as input and returns an "int"
// compute_score should use POINTS array and return the score for the string argument passed in
// chars that are NOT letters should be given 0 points
// uppercase/lowercase letters should be given same point values
// ! -> 0 points
// A or a -> 1 point
int compute_score(string word)
{
    // TODO: Compute and return score for string
    // initialize int score at 0
    // iterate through the string once (i at 0 until end)
    // check: if current letter is uppercase?
    // - we add score to POINTS[word[i] - 'A'] -> we get the word - ASCII value 'A'
    // else if current letter is lowercase?
    // - we add score to POINTS[word[i] - 'a'] -> we get the word - ASCII value 'a'
    // return final score

    int score = 0;
    for (int i = 0; i < strlen(word); i++)
    {
        if (isupper(word[i]))
        {
            score += POINTS[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            score += POINTS[word[i] - 'a'];
        }
    }
    return score;
}

// test -> $ check50 cs50/labs/2023/x/scrabble
// style -> $ style50 scrabble.c
// submit -> $ submit50 cs50/labs/2023/x/scrabble