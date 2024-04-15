#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // TODO: Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else
    {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    // TODO: Compute and return score for string
    // code could be smaller indeed
    int x = 0;
    for (int scoresum = 0, n = strlen(word); scoresum < n; scoresum++)
    {

        if (word[scoresum] == 65 || word[scoresum] == 97)
        {
            x += POINTS[0];
        }
        else if (word[scoresum] == 66 || word[scoresum] == 98)
        {
            x += POINTS[1];
        }
        else if (word[scoresum] == 67 || word[scoresum] == 99)
        {
            x += POINTS[2];
        }
        else if (word[scoresum] == 68 || word[scoresum] == 100)
        {
            x += POINTS[3];
        }
        else if (word[scoresum] == 69 || word[scoresum] == 101)
        {
            x += POINTS[4];
        }
        else if (word[scoresum] == 70 || word[scoresum] == 102)
        {
            x += POINTS[5];
        }
        else if (word[scoresum] == 71 || word[scoresum] == 103)
        {
            x += POINTS[6];
        }
        else if (word[scoresum] == 72 || word[scoresum] == 104)
        {
            x += POINTS[7];
        }
        else if (word[scoresum] == 73 || word[scoresum] == 105)
        {
            x += POINTS[8];
        }
        else if (word[scoresum] == 74 || word[scoresum] == 106)
        {
            x += POINTS[9];
        }
        else if (word[scoresum] == 75 || word[scoresum] == 107)
        {
            x += POINTS[10];
        }
        else if (word[scoresum] == 76 || word[scoresum] == 108)
        {
            x += POINTS[11];
        }
        else if (word[scoresum] == 77 || word[scoresum] == 109)
        {
            x += POINTS[12];
        }
        else if (word[scoresum] == 78 || word[scoresum] == 110)
        {
            x += POINTS[13];
        }
        else if (word[scoresum] == 79 || word[scoresum] == 111)
        {
            x += POINTS[14];
        }
        else if (word[scoresum] == 80 || word[scoresum] == 112)
        {
            x += POINTS[15];
        }
        else if (word[scoresum] == 81 || word[scoresum] == 113)
        {
            x += POINTS[16];
        }
        else if (word[scoresum] == 82 || word[scoresum] == 114)
        {
            x += POINTS[17];
        }
        else if (word[scoresum] == 83 || word[scoresum] == 115)
        {
            x += POINTS[18];
        }
        else if (word[scoresum] == 84 || word[scoresum] == 116)
        {
            x += POINTS[19];
        }
        else if (word[scoresum] == 85 || word[scoresum] == 117)
        {
            x += POINTS[20];
        }
        else if (word[scoresum] == 86 || word[scoresum] == 118)
        {
            x += POINTS[21];
        }
        else if (word[scoresum] == 87 || word[scoresum] == 119)
        {
            x += POINTS[22];
        }
        else if (word[scoresum] == 88 || word[scoresum] == 120)
        {
            x += POINTS[23];
        }
        else if (word[scoresum] == 89 || word[scoresum] == 121)
        {
            x += POINTS[24];
        }
        else if (word[scoresum] == 90 || word[scoresum] == 122)
        {
            x += POINTS[25];
        }
        else
        {
            x += 0;
        }

    }
    return x;
}
