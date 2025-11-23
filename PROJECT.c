#include <stdio.h>
#include <time.h>

int main(void) {
    int guess;
    int attempts = 0;
    int MIN;
    int MAX;
    int secret; 
    printf("Welcome to the NUMBER GUESSING GAME!\n");
    printf("Give me the range of numbers\n");
    printf("Starts from: ");
    scanf("%d", &MIN);
    printf("Ends at: ");
    scanf("%d", &MAX);
    printf("I'm thinking of a number between %d and %d.\n", MIN, MAX);
    printf("Type 0 to give up.\n\n");

    secret = (( MAX / 7 ) + MIN );

    while (1) {
        printf("Enter number you guessed : ");
        if (scanf("%d", &guess) != 1) {
            int ch;
            printf("Please enter a valid integer.\n");
            while ((ch = getchar()) != '\n' && ch != EOF) 
            continue;
        }

        if (guess == 0) {
            printf("You gave up. The number was %d. Better luck next time!\n", secret);
            break;
        }

        attempts++;

        if (guess < MIN || guess > MAX) {
            printf("Please guess a number between %d and %d (or 0 to quit).\n", MIN, MAX);
            continue;
        }

        if (guess < secret) {
            printf("Too low! Try a higher number.\n");
        } else if (guess > secret) {
            printf("Too high! Try a lower number.\n");
        } else {
            printf("CONGRATS!\nYou guessed it in %d attempt%s.\n", attempts, attempts == 1 ? "" : "s");
            break;
        }
    }

    return 0;
}