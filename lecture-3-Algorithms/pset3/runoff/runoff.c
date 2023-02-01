#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates in the election
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidate Structure has name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates with MAX 9
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {

        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break;
        }

        // Eliminate last-place candidates
        int min = find_min();
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    // if "name" is match for name of valid candidate
    // we'll update voter "rank" preference (0 is 1st, 1 is 2nd...)
    // if preference is successfully recorded we return true, else false

    // iterate over candidate_count array
    for (int i = 0; i < candidate_count; i++)
    {
        // check: comparing name and candidate name should equal to 0 for true
        if (strcmp(name, candidates[i].name) == 0)
        {
            // set preferences[i][j] as voter & rank respectively
            preferences[voter][rank] = i;
            return true;
        }
    }
    return false;
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    // update number of "votes" each candidate has at this stage
    // every voter votes for top-preferred candidate who's not eliminated

    // iterate over voter_count array
    for (int i = 0; i < voter_count; i++)
    {
        // iterate over candidate_count array
        for (int j = 0; j < candidate_count; j++)
        {
            // initialize c as preferences[voter][rank]
            int c = preferences[i][j];
            // check: if candidate NOT eliminated
            if (candidates[c].eliminated == false)
            {
                // increase candidate's votes by 1 and break out of loop
                candidates[c].votes++;
                break;
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    // if any candidate has more than half the vote, this is the winner
    // else we return false

    // iterate through candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // check: if a candidate's votes > voter_count / 2
        if (candidates[i].votes > voter_count / 2)
        {
            // print out winner and return true
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    // function returns minimum vote total for any candidate still in election

    // initialize voteCount and set to voter_count for reference
    int voteCount = voter_count;
    // iterate over candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // if current candidate is NOT eliminated
        // AND
        // candidate's votes < voteCount?
        if (candidates[i].eliminated == false && candidates[i].votes < voteCount)
        {
            // set voteCount to be a candidate's votes
            voteCount = candidates[i].votes;
        }
    }
    return voteCount;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    // function returns true if every candidate in election has same number of votes

    // initialize vars for tieCount, stillRunning at 0
    int tieCount = 0;
    int stillRunning = 0;

    // iterate over candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // check: if candidate is NOT eliminated
        // AND
        // candidate has minimum votes
        if (candidates[i].eliminated == false && candidates[i].votes == min)
        {
            tieCount++;
            stillRunning++;
        }
        // else if: candidate is NOT eliminated
        else if (candidates[i].eliminated == false)
        {
            stillRunning++;
        }
    }
    // check: if tieCount == stillRunning it means it's a tie
    if (tieCount == stillRunning)
    {
        return true;
    }
    return false;
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    // interate over candidates array
    for (int i = 0; i < candidate_count; i++)
    {
        // check: if candidate's votes are at MIN
        //  we'll set eliminated to true
        if (candidates[i].votes == min)
        {
            candidates[i].eliminated = true;
        }
    }
}

// test -> $ check50 cs50/problems/2023/x/runoff
// style -> $ style50 runoff.c
// submit -> $ submit50 cs50/problems/2023/x/runoff