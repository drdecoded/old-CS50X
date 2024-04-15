#include <stdio.h>

int main(void)
{
    char *s = "HI!";
    printf("%s\n", s);
        printf("%p\n", &s[0]);
            printf("%p\n", &s[1]);
                printf("%p\n", &s[2]);
                    printf("%p\n", &s[3]);
                        printf("%p\n", &s[4]);
                        printf("%p\n", &s[5]);
                        printf("%p\n", &s[6]);
                        printf("%p\n", &s[7]);
}