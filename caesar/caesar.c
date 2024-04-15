#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    else if (argc == 2)
    {
    bool check = only_digits(argv[1]);
        if (check == 1)
        {
            int key = atoi(argv[1]);
            string input = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int j = 0; j < strlen(input); j++)
            {
                if (isupper(input[j]))
                {
                printf("%c",(input[j] - 65 + key) % 26 + 65);
                }
                else if (islower(input[j]))
                {
                    printf("%c",(input[j] - 97 + key) % 26 + 97);
                }
                else
                {
                    printf("%c",input[j]);
                }
            }
            printf("\n");
            return 0;
        }
        else
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    return 0;
}


bool only_digits(string s)
{
    bool run = 0;
    int runcounter = 0;
    for (int count = 0, len = strlen(s); count < len; count++)
    {
        if (isdigit(s[count]))
        {
            runcounter += 0;
        }
        else
        {
            runcounter += 1;
        }
    }
    if (runcounter == 0)
    {
        run = 1;
    }
    else
    {
        run = 0;
    }
    return run;
}

char rotate(char c, int n)
{
    if (isalpha(c))
    {
        c = c + n;
        return c;


    }
    else
    {
        return c;
    }
    return 0;
}