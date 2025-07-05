#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int randomNumber;
    int no_of_guesses = 0;
    int guessed;

    // Initialize random number generator
    srand(time(0));  // Seed the random number generator with the current time

    // Generate and print a random number between 1 and 100
    randomNumber = (rand() % 100) + 1;
    // printf("Random number between 1 and 100: %d\n", randomNumber);

    do
    {
        printf("Enter the Guessed number:");
        scanf("%d",&guessed);
        if (guessed > randomNumber)
        {
            printf("Lower number please!\n");
        }
        else if (guessed < randomNumber){
            printf("Higher number please!\n");
        }
        else{
            printf("Congrats!!, your guess is right\n");
        }
        no_of_guesses++;
    } while (guessed != randomNumber);
    
    printf("You guess it in the %d guesses\n",no_of_guesses);
    return 0;
}
