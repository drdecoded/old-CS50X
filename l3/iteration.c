#include <cs50.h>
#include <stdio.h>

void draw(int number);

int main(void)
{
    int height = get_int("Height: ");

    draw(height);
}

void draw(int number)
{
    for (int i = 0; i < number; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        printf("\n");
    }
}