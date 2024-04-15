#include <cs50.h>
#include <stdio.h>

int main(void){
    int n = get_int("n: ");

    if (n % 2 == 0){
        printf("even\n");
    }
    else {
        printf("odd\n");
    }
}