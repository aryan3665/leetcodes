class Solution {
public:
int r,c;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    bool valid(int i, int j) { return (i >= 0 && j >= 0 && i < r && j < c); }
    int numEnclaves(vector<vector<int>>& board) {
        int count = 0;
        r = board.size();
        c = board[0].size();
        queue<pair<int, int>> q;

        // First row
        for (int i = 0; i < c; i++) {
            if (board[0][i] == 1) {
                q.push({0, i});
                board[0][i] = 0;
            }
        }

        // First column
        for (int i = 0; i < r; i++) {
            if (board[i][0] == 1) {
                q.push({i, 0});
                board[i][0] = 0;
            }
        }

        // Last row
        for (int i = 0; i < c; i++) {
            if (board[r - 1][i] == 1) {
                q.push({r - 1, i});
                board[r - 1][i] = 0;
            }
        }

        // Last column (fixed bug here)
        for (int i = 0; i < r; i++) {
            if (board[i][c - 1] == 1) {
                q.push({i, c - 1});
                board[i][c - 1] = 0;
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
                if (valid(nx, ny) && board[nx][ny] == 1) {
                    board[nx][ny] = 0;
                    q.push({nx, ny});
                }
            }
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (board[i][j] == 1) {
                    count++;
                }
            }
        }
        return count;
    }
};