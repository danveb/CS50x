#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates (constant MAX is 9)
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Vote: ");

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO
    // iterate through candidates array
    // check: if current name matches a candidate in candidate array?
    // increase its vote and return true
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(name, candidates[i].name) == 0)
        {
            candidates[i].votes++;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO
    // function should print out name of candidate who received most votes
    // initialize winner at 0
    // iterate over candidates array
    // check: if votes from current candidate > winner?
    // set winner = to current candidate's vote
    int winner = 0;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > winner)
        {
            winner = candidates[i].votes;
        }
    }

    // print all candidates that match highest vote count
    // iterate over candidates array
    // check: if current candidate's votes are winner?
    // we'll print a new line and return name
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes == winner)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}

// test -> $ check50 cs50/problems/2023/x/plurality
// style -> $ style50 plurality.c
// submit -> $ check50 cs50/problems/2023/x/plurality