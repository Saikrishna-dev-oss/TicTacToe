#include <stdio.h>
#include <stdlib.h>

// Function declarations
void printboard();           // Prints the current state of the game board
int checkwin();              // Checks for a win or draw condition
int checkrows();             // Checks all rows for a win
int checkcolumns();          // Checks all columns for a win
int checkdiagonals();        // Checks both diagonals for a win
void clearscreen();          // Clears the console screen

// Game board represented as a character array
char board[] = {'0','1','2','3','4','5','6','7','8','9'};

// Main function
int main() {
    int input, player = 1, i = -1;
    char mark;

    printboard();  // Display initial board

    while (i == -1) {
        // Determine current player and their mark
        player = (player % 2 == 0) ? 2 : 1;
        mark   = (player == 1) ? 'X' : 'O';

        // Prompt player for input
        printf("Enter your choice for player %d: ", player);

        // Input validation: check if scanf successfully reads an integer
        if (scanf("%d", &input) != 1) {
            printf("Invalid input! Please enter a number between 1 and 9.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        // Validate move: must be within range and unoccupied
        if (input < 1 || input > 9 || board[input] == 'X' || board[input] == 'O') {
            printf("Invalid move !! Try Again.\n");
            continue;
        }

        // Update board with player's mark
        board[input] = mark;
        printboard();  // Show updated board

        // Check game status
        int result = checkwin();
        if (result == 1) {
            printf("\nPlayer %d has won the match !!\n", player);
            break;
        } else if (result == 0) {
            printf("\nMatch Draw !!\n\n\n");
            break;
        }

        player++;  // Switch to next player
    }

    return 0;
}

// Function to print the current game board
void printboard() {
    clearscreen();  // Clear screen before printing

    printf("\n\n--- WELCOME TO TIC TAC TOE ---\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1], board[2], board[3]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[4], board[5], board[6]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[7], board[8], board[9]);
    printf("     |     |     \n");
    printf("\n\n");
}

// Function to check for win or draw
int checkwin() {
    if (checkrows() || checkcolumns() || checkdiagonals()) {
        return 1;  // Win
    }

    // Check for draw: all positions filled
    int count = 0;
    for (int i = 1; i <= 9; i++) {
        if (board[i] == 'X' || board[i] == 'O') {
            count++;
        }
    }

    if (count == 9) return 0;  // Draw

    return -1;  // Game still in progress
}

// Check all rows for a win
int checkrows() {
    // Top row
    if (board[1] == board[2] && board[2] == board[3]) return 1;
    // Middle row
    if (board[4] == board[5] && board[5] == board[6]) return 1;
    // Bottom row
    if (board[7] == board[8] && board[8] == board[9]) return 1;
    return 0;
}

// Check all columns for a win
int checkcolumns() {
    // Left column
    if (board[1] == board[4] && board[4] == board[7]) return 1;
    // Middle column
    if (board[2] == board[5] && board[5] == board[8]) return 1;
    // Right column
    if (board[3] == board[6] && board[6] == board[9]) return 1;
    return 0;
}

// Check both diagonals for a win
int checkdiagonals() {
    // Left-to-right diagonal
    if (board[1] == board[5] && board[5] == board[9]) return 1;
    // Right-to-left diagonal
    if (board[3] == board[5] && board[5] == board[7]) return 1;
    return 0;
}

// Function to clear the console screen
void clearscreen() {
    system("cls");  // Windows-specific command to clear screen
}