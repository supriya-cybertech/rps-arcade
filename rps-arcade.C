// Rock Paper Scissors Game in C
// Author: Supriya
// Modern, colorful & replayable version

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h> // for sleep()

// ANSI color codes for colorful terminal text
#define GREEN   "\x1b[32m"
#define RED     "\x1b[31m"
#define YELLOW  "\x1b[33m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

// Function to determine the winner
int playRound(char you, char computer) {
    if (you == computer)
        return -1; // Draw
    if ((you == 's' && computer == 'z') ||
        (you == 'p' && computer == 's') ||
        (you == 'z' && computer == 'p'))
        return 1; // Win
    else
        return 0; // Lose
}

int main() {
    system("chcp 65001 > nul"); // Enable UTF-8 on Windows terminal

    srand(time(NULL)); // Seed random number generator
    int wins = 0, losses = 0, draws = 0;
    char you, computer, playAgain;

    printf(CYAN "\n==============================\n" RESET);
    printf(CYAN "     🪨  ROCK PAPER SCISSORS  ✂️\n" RESET);
    printf(CYAN "==============================\n" RESET);

    do {
        // Computer's random choice
        int n = rand() % 3;
        if (n == 0) computer = 's';
        else if (n == 1) computer = 'p';
        else computer = 'z';

        // User input
        printf("\nEnter your choice: "
               "\n's' for Stone 🪨"
               "\n'p' for Paper 📄"
               "\n'z' for Scissor ✂️"
               "\n👉 Your choice: ");
        scanf(" %c", &you);

        // Input validation
        if (you != 's' && you != 'p' && you != 'z') {
            printf(RED "Invalid input! Please enter s, p, or z.\n" RESET);
            continue;
        }

        // Simulate computer "thinking"
        printf("\nComputer is choosing");
        for (int i = 0; i < 3; i++) {
            printf(".");
            fflush(stdout);
            sleep(1);
        }
        printf("\n");

        // Play one round
        int result = playRound(you, computer);

        // Display result
        if (result == -1) {
            printf(YELLOW "\nIt's a Draw! 😐\n" RESET);
            draws++;
        } else if (result == 1) {
            printf(GREEN "\nYou Win! 🎉\n" RESET);
            wins++;
        } else {
            printf(RED "\nYou Lose! 😢\n" RESET);
            losses++;
        }

        // Show choices
        printf(CYAN "\nYou chose: %c | Computer chose: %c\n" RESET, you, computer);

        // Scoreboard
        printf(YELLOW "\n----------------------------------\n" RESET);
        printf("🏆 Wins: %d | ❌ Losses: %d | 🤝 Draws: %d\n", wins, losses, draws);
        printf(YELLOW "----------------------------------\n" RESET);

        // Ask if user wants to play again
        printf("\nPlay again? (y/n): ");
        scanf(" %c", &playAgain);

    } while (playAgain == 'y' || playAgain == 'Y');

    // Final summary
    printf(CYAN "\n==============================\n" RESET);
    printf(GREEN "Thanks for playing! 🎮\n" RESET);
    printf("Final Score → Wins: %d | Losses: %d | Draws: %d\n", wins, losses, draws);
    printf(CYAN "==============================\n" RESET);

    return 0;
}


