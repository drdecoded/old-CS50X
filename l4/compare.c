#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    char *i = get_string("i: ");
    char *j = get_string("j: ");

    printf("%p\n",i);
    printf("%p\n",j);
}