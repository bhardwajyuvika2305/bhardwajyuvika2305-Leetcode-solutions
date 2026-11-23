/*You are given an m x n matrix board containing letters 'X' and 'O', capture regions that are surrounded:
Connect: A cell is connected to adjacent cells horizontally or vertically.
Region: To form a region connect every 'O' cell.
Surround: A region is surrounded if none of the 'O' cells in that region are on the edge of the board. Such regions are completely enclosed by 'X' cells.
To capture a surrounded region, replace all 'O's with 'X's in-place within the original board. You do not need to return anything. */

// Solution :- 

class Solution {
private:
    void dfs(vector<vector<char>>& board, int r, int c, int m, int n) {
        if (r < 0 || r >= m || c < 0 || c >= n || board[r][c] != 'O') {
            return;
        }
        
        board[r][c] = '#';
        
        dfs(board, r + 1, c, m, n);
        dfs(board, r - 1, c, m, n);
        dfs(board, r, c + 1, m, n);
        dfs(board, r, c - 1, m, n);
    }

public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        if (m == 0) return;
        int n = board[0].size();
        
        // 1. Start DFS from 'O's on the first and last rows
        for (int c = 0; c < n; ++c) {
            if (board[0][c] == 'O') dfs(board, 0, c, m, n);
            if (board[m - 1][c] == 'O') dfs(board, m - 1, c, m, n);
        }
        
        // 2. Start DFS from 'O's on the first and last columns
        for (int r = 0; r < m; ++r) {
            if (board[r][0] == 'O') dfs(board, r, 0, m, n);
            if (board[r][n - 1] == 'O') dfs(board, r, n - 1, m, n);
        }
        
        // 3. Capture surrounded 'O's and restore safe '#' cells to 'O'
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                } else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};
