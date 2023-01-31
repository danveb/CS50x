#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;

    // print average of test scores
    // printf("Average: %i\n", (score1 + score2 + score3) / 3);
    // Average: 59

    // Option #1
    // we use 3.0 to have a more precise data type for math to work out
    // printf("Average: %f\n", (score1 + score2 + score3) / 3.0);
    // Average: 59.33333

    // Option #2
    // we use "type casting" to explictly make sure 3 is a float
    // printf("Average: %f\n", (score1 + score2 + score3) / (float) 3);
    // Average: 59.333332

    // ARRAY
    // declare scores array of size 3
    // int scores[3];
    // scores[0] = get_int("Score 1: ");
    // scores[1] = get_int("Score 2: ");
    // scores[2] = get_int("Score 3: ");

    int scores[3];
    for (int i = 0; i < 3; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) 3);
}