/*The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return the number of distinct solutions to the n-queens puzzle.*/

// Solution :-

class Solution {
private:
    int count = 0;

    void backtrack(int row, int n, int cols, int diag1, int diag2) {
        if (row == n) {
            count++;
            return;
        }

        // Available positions in the current row
        for (int col = 0; col < n; col++) {
            // Check column, main diagonal (row - col), and anti-diagonal (row + col)
            int d1 = row - col + n;
            int d2 = row + col;

            if ((cols & (1 << col)) || (diag1 & (1 << d1)) || (diag2 & (1 << d2))) {
                continue;
            }

            // Place queen (set bits)
            backtrack(row + 1, n, cols | (1 << col), diag1 | (1 << d1), diag2 | (1 << d2));
        }
    }

public:
    int totalNQueens(int n) {
        count = 0;
        backtrack(0, n, 0, 0, 0);
        return count;
    }
};