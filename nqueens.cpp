#include <iostream>
using namespace std;


#define MAX_N 20


int board[MAX_N];


bool isSafe(int row, int col, int n) {
   
    for (int prevRow = 0; prevRow < row; prevRow++) {
        int prevCol = board[prevRow]; 

        if (prevCol == col ||                  
            prevRow + prevCol == row + col ||   
            prevRow - prevCol == row - col) {  
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

  
    for (int col = 0; col < n; col++) {
        if (isSafe(row, col, n)) {
            board[row] = col; 
            solveNQueens(row + 1, n); 
           
        }
    }
}

int main() {
    int n;

    
    cout << "Enter board size (N): ";
    cin >> n;

 
    for (int i = 0; i < n; i++) {
        board[i] = -1; 
    }

    
    solveNQueens(0, n);

    return 0;
}
