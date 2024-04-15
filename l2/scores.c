#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x = get_int("How many storage? ");
    int n = get_int("How many scores? ");

    int scores[x];

    for (int i = 0; i < n; i++)
    {
        scores[i] = get_int("Score: ");
    }

    printf("Average: %f\n", (scores[0] + scores[1] + scores[2])/3.0);

}