#include <cs50.h>
#include <stdio.h>

int main (void)
{
    string s = "HI!";
    char *p = &s[0];
    printf("%p\n",s);
    printf("%p\n",p);
}