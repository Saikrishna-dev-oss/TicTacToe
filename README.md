# TicTacToe
Tic Tac Toe in C

A simple console-based Tic Tac Toe game written in C. Two players take turns marking spaces on a 3×3 grid until one wins or the game ends in a draw.

---

## ✨Features

- Two-player mode  
- Input validation for invalid and non-numeric entries  
- Win and draw detection  
- Modular code with clear comments  
- Console screen clearing for better UX (Windows only)

---

## How to Run

### Compile the code:
gcc main.c -o tictactoe

## Run the Executable
./tictactoe     # Linux/macOS
tictactoe.exe   # Windows

## Note: 
This game uses system("cls") to clear the screen, which works on Windows. If you're on Linux/macOS, replace it with system("clear").

## 🎮 Gameplay Instructions
The board is labeled from 1 to 9.
Player 1 uses X, Player 2 uses O.
Players take turns to enter the number of the cell they want to mark.
The game ends when:
   One player has three marks in a row (win), or
   All cells are filled without a winner (draw)

## 🧱 Built With
Language: C
Platform: Console

## 👤Author
-Mangali Sai Krishna
-Geethanjali College Of Engineering and Technology

