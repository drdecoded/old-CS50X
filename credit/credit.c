#include <cs50.h>
#include <stdio.h>

long get_cc(void);
long input;

int main(void)
{
    long cc = get_cc();
}

long get_cc(void)
{
    bool run = true;

    while (true)
    {
        input = get_long("Credit Card Number: ");

        if (input > 339999999999999 && input < 350000000000000)
        {
            printf("AMEX\n");
            return input;
        }
        else if (input > 369999999999999 && input < 380000000000000)
        {
            printf("AMEX\n");
            return input;
        }
        else if (input > 5099999999999999 && input < 5600000000000000)
        {
            printf("MASTERCARD\n");
            return input;
        }
        else if (input > 3999999999999 && input < 4222222222223)
        {
            printf("VISA\n");
            return input;
        }
        else if (input > 3999999999999999 && input < 4111111111111112)
        {
            printf("VISA\n");
            return input;
        }
        else
        {
            printf("INVALID\n");
            return input;
        }
    }
}