#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Generates a random move for the computer
int generateComputerMove() {
    return rand() % 3; // Generate a random number between 0 and 2
}

// Determines the winner of the game
int determineWinner(int userMove, int computerMove) {
    // If the moves are the same, it's a tie
    if (userMove == computerMove) {
        return 0; // Tie
    }

    // Determine the winner based on the game rules
    // Rock: 0, Paper: 1, Scissors: 2
    if ((userMove == 0 && computerMove == 2) ||
        (userMove == 1 && computerMove == 0) ||
        (userMove == 2 && computerMove == 1)) {
        return 1; // User wins
    } else {
        return -1; // Computer wins
    }
}

// Displays the result of the game
void displayResult(int result) {
    if (result == 0) {
        printf("It's a tie!\n");
    } else if (result == 1) {
        printf("You win!\n");
    } else {
        printf("You lose!\n");
    }
}

int main() {
    int playAgain = 1;

    srand(time(0)); // Initialize the seed for random numbers

    while (playAgain) {
        int userMove, computerMove, result;

        // Prompt the user for their move
        printf("Choose your move:\n");
        printf("1 - Rock\n");
        printf("2 - Paper\n");
        printf("3 - Scissors\n");
        scanf("%d", &userMove);

        if (userMove < 1 || userMove > 3) {
            printf("Invalid move. Please choose a number between 1 and 3.\n");
            continue;
        }

        userMove--; // Adjust the entered value to match array indices

        computerMove = generateComputerMove(); // Get the computer's move
        result = determineWinner(userMove, computerMove); // Determine the winner

        // Display the computer's move
        char *options[] = {"Rock", "Paper", "Scissors"};
        printf("The computer chose: %s\n", options[computerMove]);

        displayResult(result); // Display the result of the game

        // Ask the user if they want to play again
        printf("Do you want to play again? (Y/N): ");
        char response[2];
        scanf("%s", response);

        if (response[0] == 'N' || response[0] == 'n') {
            playAgain = 0; // Exit the loop if the user doesn't want to play again
        }
    }

    return 0;
}
