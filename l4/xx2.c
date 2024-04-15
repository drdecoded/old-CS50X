#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int numbers[] = {4,5,7,2,1,3,5};

    printf("%i\n", numbers[0]);
    printf("%i\n", *numbers);
    printf("%i\n", *(numbers+2));
}