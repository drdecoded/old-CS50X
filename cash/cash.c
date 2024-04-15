#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
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

int calculate_nickels(int cents)
{
    int cn;
    cn = cents / 5;
    return cn;
}

int calculate_pennies(int cents)
{
    int cp;
    cp = cents / 1;
    return cp;
}
