#include <cs50.h>
#include <stdio.h>

int main(void){
    char c = get_char("Do you agree? ");

    if (c = 'y' || c = "Yes"){
        printf("Agreed.\n");
    }
    else if (c = "no" || c = "No"){
        printf("Not agreed!\n");
    }

}