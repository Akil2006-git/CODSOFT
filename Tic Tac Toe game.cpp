#include <iostream>
using namespace std;

// 3x3 Tic-Tac-Toe grid
char grid[3][3];

// Tracks current player symbol ('X' or 'O')
char turn = 'X';

// A Function that initialize the board with numbers 1 to 9
void setupBoard() {
    char count = '1';
    for (int r = 0; r < 3; ++r) {
        for (int c = 0; c < 3; ++c) {
            grid[r][c] = count++;
        }
    }
}

// A Function that show the current state of the board
void printBoard() {
    cout << "\n";
    for (int i = 0; i < 3; ++i) {
        cout << " ";
        for (int j = 0; j < 3; ++j) {
            cout << grid[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n\n";
}

// Convert player input (1-9) to grid position
bool placeMark(int choice) {
    int row = (choice - 1) / 3;
    int col = (choice - 1) % 3;

    if (choice < 1 || choice > 9 || grid[row][col] == 'X' || grid[row][col] == 'O') {
        return false;
    }

    grid[row][col] = turn;
    return true;
}

// Check if current player has won
bool isWin() {
    for (int i = 0; i < 3; ++i) {
        if (grid[i][0] == turn && grid[i][1] == turn && grid[i][2] == turn) return true;
        if (grid[0][i] == turn && grid[1][i] == turn && grid[2][i] == turn) return true;
    }

    if (grid[0][0] == turn && grid[1][1] == turn && grid[2][2] == turn) return true;
    if (grid[0][2] == turn && grid[1][1] == turn && grid[2][0] == turn) return true;

    return false;
}

// Check if the board is full and it's a draw
bool isDraw() {
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            if (grid[i][j] != 'X' && grid[i][j] != 'O')
                return false;
    return true;
}

// Switch the player
void nextTurn() {
    turn = (turn == 'X') ? 'O' : 'X';
}

int main() {
    char again;

    do {
        setupBoard();
        turn = 'X';
        bool gameOver = false;

        while (!gameOver) {
            printBoard();
            int move;

            cout << "Player " << turn << ", choose a cell (1-9): ";
            cin >> move;

            if (!placeMark(move)) {
                cout << "Invalid move. Try another cell.\n";
                continue;
            }

            if (isWin()) {
                printBoard();
                cout << "Player " << turn << " wins!\n";
                gameOver = true;
            } else if (isDraw()) {
                printBoard();
                cout << "It's a draw!\n";
                gameOver = true;
            } else {
                nextTurn();
            }
        }

        cout << "Play again? (y/n): ";
        cin >> again;

    } while (again == 'y' || again == 'Y');

    cout << "Game Over. Thanks for playing!\n";
    return 0;
}
