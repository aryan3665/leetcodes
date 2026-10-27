class Solution {
public:
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};

    bool isvalid(int x, int y, int n, int m) {
        return x >= 0 && x < n && y >= 0 && y < m;
    }

    long long bfs(vector<vector<int>>& grid, int i, int j) {
        long long sum = grid[i][j];

        queue<pair<int, int>> q;
        q.push({i, j});
        grid[i][j] = 0;

        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nx = x + row[k];
                int ny = y + col[k];

                if (isvalid(nx, ny, grid.size(), grid[0].size())
                    && grid[nx][ny] > 0) {

                    sum += grid[nx][ny];
                    q.push({nx, ny});
                    grid[nx][ny] = 0;
                }
            }
        }

        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int c = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0) {
                    long long sum = bfs(grid, i, j);

                    if (sum % k == 0) {
                        c++;
                    }
                }
            }
        }

        return c;
    }
};