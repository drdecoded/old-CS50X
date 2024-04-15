#include <cs50.h>
#include <stdio.h>

int main(void){

    const int MINE = 2;
    int points = get_int("How many point did you lose? ");

    if (points < MINE){
        printf("You lost fewer point than me.\n");
    }
    else if (points > MINE){
        printf("You lost more points than me.\n");
    }
    else{
        printf("You lost the same number of points as me.\n");
    }
}