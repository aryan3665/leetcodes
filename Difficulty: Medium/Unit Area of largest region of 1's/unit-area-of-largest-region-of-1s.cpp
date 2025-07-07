class Solution {
  public:
    int m, n;
    int row[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    int col[8] = {0, 1, 1, 1, 0, -1, -1, -1};

    bool isvalid(int i, int j) {
        return (i >= 0 && j >= 0 && i < m && j < n);
    }

    int findMaxArea(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxi = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int c = 1;
                    grid[i][j] = 0; // Mark visited
                    queue<pair<int, int>> q;
                    q.push({i, j});

                    while (!q.empty()) {
                        int x1 = q.front().first;
                        int y1 = q.front().second;
                        q.pop();

                        for (int k = 0; k < 8; k++) {
                            int nx = x1 + row[k];
                            int ny = y1 + col[k];
                            if (isvalid(nx, ny) && grid[nx][ny] == 1) {
                                q.push({nx, ny});
                                grid[nx][ny] = 0; // Mark visited
                                c++;
                            }
                        }
                    }
                    maxi = max(maxi, c);
                }
            }
        }

        return maxi;
    }
};
