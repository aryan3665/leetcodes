class Solution {
public:
    int r, c;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};
    bool issafe(int i, int j) { return (i >= 0 && j >= 0 && i < r && j < c); }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int result = 0;
        queue<pair<int, int>> q;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1) {
                    q.push({i, j});
                    grid[i][j] = 0;
                }
                int tempcount = 0;
                while (!q.empty()) {
                    auto it = q.front();
                    int x = it.first;
                    int y = it.second;
                    q.pop();
                    tempcount++;

                    for (int k = 0; k < 4; k++) {
                        int nx = x + row[k];
                        int ny = y + col[k];
                        if (issafe(nx, ny) && grid[nx][ny] == 1) {
                            grid[nx][ny] = 0;

                            q.push({nx, ny});
                        }
                    }
                }
                result = max(result, tempcount);
            }
        }
        return result;
    }
};