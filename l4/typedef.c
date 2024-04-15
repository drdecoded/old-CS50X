#include <stdio.h>

typedef struct
{
    char *string;
}
string;
 // not working
int main(void)
{
    string i = "HI!";
    printf("%s",i);
}