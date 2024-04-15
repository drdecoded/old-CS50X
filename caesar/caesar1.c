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
            int argvtoint = atoi(argv[1]);
            printf("%i\n",argvtoint);
            string input = get_string("plaintext: ");
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
    return 0;
}