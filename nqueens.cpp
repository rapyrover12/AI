#include <iostream>
using namespace std;

// Maximum board size
#define MAX_N 20

// Global board array: board[row] = col where queen is placed
int board[MAX_N];

// Function to check if placing a queen at (row, col) is safe
bool isSafe(int row, int col, int n) {
    // Check previous rows for conflicts
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = board[prevRow]; // Column of queen in prevRow

        // Conflict if: same column or same diagonal
        if (prevCol == col ||                   // Same column
            prevRow + prevCol == row + col ||   // Same main diagonal
            prevRow - prevCol == row - col) {   // Same anti-diagonal
            return false;
        }
    }
    return true;
}

// Recursive function to solve N-Queens
void solveNQueens(int row, int n) {
    // Base case: All queens placed
    if (row == n) {
        // Print solution
        cout << "Solution:\n";
        for (int i = 0; i < n; i++) {
            cout << "(" << i << ", " << board[i] << ") ";
        }
        cout << endl;
        return;
    }

    // Try placing queen in each column of current row
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row] = col; // Place queen
            solveNQueens(row + 1, n); // Solve for next row
            // Backtrack: No need to undo board[row] (overwritten next)
        }
    }
}

int main() {
    int n;

    // Input board size
    cout << "Enter board size (N): ";
    cin >> n;

    // Initialize board
    for (int i = 0; i < n; i++) {
        board[i] = -1; // No queens placed yet
    }

    // Solve N-Queens
    solveNQueens(0, n);

    return 0;
}