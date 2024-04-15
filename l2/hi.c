#include <cs50.h>
#include <stdio.h>

int main(void)
{
    char c1 = 'H';
    char c2 = 'I';
    char c3 = '!';

    printf("%i %i %i\n",(int) c1,(int) c2, (int) c3);

    int c4 = 72;
    int c5 = 73;
    int c6 = 33;

    printf("%c%c%c\n", (char) c4, (char) c5, (char) c6);
}