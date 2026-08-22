/* The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.
Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.
Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.
*/


// Solution :- 

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        // Tracking sets/arrays for O(1) safety checks
        vector<bool> cols(n, false);
        vector<bool> diag1(2 * n - 1, false); // row + col
        vector<bool> diag2(2 * n - 1, false); // row - col + (n - 1)

        backtrack(0, n, board, result, cols, diag1, diag2);
        return result;
    }

private:
    void backtrack(int row, int n, vector<string>& board, vector<vector<string>>& result,
                   vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2) {
        if (row == n) {
            result.push_back(board);
            return;
        }

        for (int col = 0; col < n; ++col) {
            int d1 = row + col;
            int d2 = row - col + (n - 1);

            // Skip if column or diagonals are already under attack
            if (cols[col] || diag1[d1] || diag2[d2]) continue;

            // Place Queen
            board[row][col] = 'Q';
            cols[col] = diag1[d1] = diag2[d2] = true;

            // Move to next row
            backtrack(row + 1, n, board, result, cols, diag1, diag2);

            // Backtrack (Remove Queen)
            board[row][col] = '.';
            cols[col] = diag1[d1] = diag2[d2] = false;
        }
    }
};