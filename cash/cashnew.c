#include <cs50.h>
#include <stdio.h>

int get_cents();
int calculate_quarters();
int calculate_dimes();

int main(void)
{
        int cents = get_cents();

        int quarters = calculate_quarters(cents);
        cents = cents - quarters * 25;

        int dimes = calculate_dimes(cents);
        cents = cents - dimes * 10;

        printf("\nQuarters: %i\n", quarters);
        printf("\nDimes: %i\n", dimes);
}




int get_cents(void)
{
    int cprompt;
    do
    {
        cprompt = get_int("How many cents I owe you? ");
    }
    while (cprompt < 0);
    return cprompt;
}

int calculate_quarters(int cents)
{
    int cq;
    cq = cents / 25;
    return cq;
}

int calculate_dimes(int cents)
{
    int cd;
    cd = cents / 10;
    return cd;
}
