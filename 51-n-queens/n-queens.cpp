class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> solutions;
        vector<string> board(n, string(n, '.')); // Initialize the board with empty spaces
        backtrack(solutions, board, 0, n);
        return solutions;
    }

private:
    void backtrack(vector<vector<string>>& solutions, vector<string>& board, int row, int n) {
        if (row == n) {
            solutions.push_back(board); // Found a valid configuration
            return;
        }

        for (int col = 0; col < n; ++col) {
            if (isValid(board, row, col, n)) {
                board[row][col] = 'Q'; // Place the queen
                backtrack(solutions, board, row + 1, n); // Move to the next row
                board[row][col] = '.'; // Backtrack
            }
        }
    }

    bool isValid(const vector<string>& board, int row, int col, int n) {
        // Check the column
        for (int i = 0; i < row; ++i) {
            if (board[i][col] == 'Q') return false;
        }
        // Check the upper left diagonal
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j] == 'Q') return false;
        }
        // Check the upper right diagonal
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j) {
            if (board[i][j] == 'Q') return false;
        }
        return true; // Valid placement
    }
};
