class Solution {
  public:
    int r, c;
    int row[4] = {0, 0, -1, 1};  // left, right, up, down
    int col[4] = {-1, 1, 0, 0};

    bool isvalid(int i, int j) {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    // Function to find whether a path exists from the source to destination.
    bool is_Possible(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();

        vector<vector<bool>> visited(r, vector<bool>(c, false));
        queue<pair<int, int>> q;

        // Find the source and push to queue
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    visited[i][j] = true;
                }
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

                if (isvalid(nx, ny) && !visited[nx][ny] && grid[nx][ny] != 0) {
                    if (grid[nx][ny] == 2) return true;
                    visited[nx][ny] = true;
                    q.push({nx, ny});
                }
            }
        }

        return false;
    }
};
