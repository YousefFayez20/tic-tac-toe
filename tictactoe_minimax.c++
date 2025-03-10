#include <iostream>
using namespace std;

bool IsEqual3(char x, char y, char z) {
    return (x == y && x == z && x != ' ');
}

int GetStatus(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (IsEqual3(board[i][0], board[i][1], board[i][2])) {
            return (board[i][0] == 'X') ? 2 : -2;
        }
        if (IsEqual3(board[0][i], board[1][i], board[2][i])) {
            return (board[0][i] == 'X') ? 2 : -2;
        }
    }
    if (IsEqual3(board[0][0], board[1][1], board[2][2]) || IsEqual3(board[2][0], board[1][1], board[0][2])) {
        return (board[1][1] == 'X') ? 2 : -2;
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return 0; // Game still ongoing
            }
        }
    }
    return 1; // Tie
}

void drawboard(char board[3][3]) {
    cout << "Current Board:\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << '|' << board[i][j] << '|';
        }
        cout << "\n---------\n";
    }
}

int minimax(char board[3][3], int depth, bool isMaximum) {
    int result = GetStatus(board);
    if (result == 2 || result == -2 || result == 1 || depth == 0) return result;
    
    int bestScore = isMaximum ? -10 : 10;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = isMaximum ? 'X' : 'O';
                int score = minimax(board, depth - 1, !isMaximum);
                board[i][j] = ' '; // Undo move
                bestScore = isMaximum ? max(bestScore, score) : min(bestScore, score);
            }
        }
    }
    return bestScore;
}

void bestMoveAI(char board[3][3]) {
    int bestScore = 10;
    int moveRow = -1, moveCol = -1;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                int score = minimax(board, 100, true);
                board[i][j] = ' '; // Undo move
                if (score < bestScore) {
                    bestScore = score;
                    moveRow = i;
                    moveCol = j;
                }
            }
        }
    }
    board[moveRow][moveCol] = 'O';
    cout << "AI played at: (" << moveRow << ", " << moveCol << ")\n";
}

int main() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    drawboard(board);

    char player = 'X';
    int status = 0;

    while (status == 0) {
        if (player == 'X') {
            int row, column;
            cout << "Enter row and column (0-2): ";
            cin >> row >> column;
            if (board[row][column] == ' ') {
                board[row][column] = 'X';
            } else {
                cout << "Slot taken! Try again.\n";
                continue;
            }
        } else {
            bestMoveAI(board);
        }
        drawboard(board);
        status = GetStatus(board);
        if (status == 2) {
            cout << "X wins!\n";
            break;
        } else if (status == -2) {
            cout << "O wins!\n";
            break;
        } else if (status == 1) {
            cout << "It's a tie!\n";
            break;
        }
        player = (player == 'X') ? 'O' : 'X';
    }
    return 0;
}
