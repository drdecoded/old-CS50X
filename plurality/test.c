#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
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

bool vote(string name);
void print_winner(void);


int main(void)
{

    int counte = get_int("Voters: ");

    for (int getname = 0; getname < counte; getname++)
    {
    string input = get_string("Name: ");
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].name = input;
            candidates[i].votes = 0;
        }
    }

    candidate_count = counte;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
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
        print_winner();
}

bool vote(string name)
{
    for (int i = 0; i <= MAX; i++)
    {
        if (strcmp(candidates[i].name, name) == 0)
        {
            candidates[i].votes += 1;
            return true;
        }
    }
    return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    if (candidates[0].votes > candidates[1].votes)
    {
        printf("%s won!",candidates[0].name);
    }
    return;
}