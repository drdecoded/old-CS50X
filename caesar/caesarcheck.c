#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

char rotate(char c, int n);
int key = 1;

int main(void)
{
    char input = get_char("plaintext: ");
    char output = rotate(input,key);
    printf("%i\n",(int) output);


}

char rotate(char c, int n)
{

    for (int letter = 0, len = strlen(c); letter < len; letter++)
    {
        if (c = 'a')
        {
            printf("its a");
        }
    }
    return 0;
}

