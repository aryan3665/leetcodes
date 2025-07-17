class Solution {
public:
    int r, c;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    bool valid(int i, int j) {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        queue<pair<int, int>> q;
        r = board.size();
        c = board[0].size();

        // First row
        for (int i = 0; i < c; i++) {
            if (board[0][i] == 'O') {
                q.push({0, i});
                board[0][i] = 'T';
            }
        }

        // First column
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 'O') {
                q.push({i, 0});
                board[i][0] = 'T';
            }
        }

        // Last row
        for (int i = 0; i < c; i++) {
            if (board[r - 1][i] == 'O') {
                q.push({r - 1, i});
                board[r - 1][i] = 'T';
            }
        }

        // Last column (fixed bug here)
        for (int i = 0; i < r; i++) {
            if (board[i][c - 1] == 'O') {
                q.push({i, c - 1});
                board[i][c - 1] = 'T';
            }
        }

        // BFS
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + row[k];
                int ny = y + col[k];
                if (valid(nx, ny) && board[nx][ny] == 'O') {
                    board[nx][ny] = 'T';
                    q.push({nx, ny});
                }
            }
        }

        // Final conversion
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 'O') {
                    board[i][j] = 'X';
                }
                if (board[i][j] == 'T') {
                    board[i][j] = 'O';
                }
            }
        }
    }
};
