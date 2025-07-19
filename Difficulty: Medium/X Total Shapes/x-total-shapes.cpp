class Solution {
public:
    int r, c;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    bool isvalid(int i, int j) {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    // Function to find the number of 'X' total shapes.
    int xShape(vector<vector<char>>& grid) {
        r = grid.size();
        c = grid[0].size();
        int count = 0;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 'X') {
                    count++;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    grid[i][j] = 'O';  // mark as visited

                    while (!q.empty()) {
                        int x = q.front().first;
                        int y = q.front().second;
                        q.pop();

                        for (int k = 0; k < 4; k++) {
                            int nx = x + row[k];
                            int ny = y + col[k];

                            if (isvalid(nx, ny) && grid[nx][ny] == 'X') {
                                grid[nx][ny] = 'O';
                                q.push({nx, ny});
                            }
                        }
                    }
                }
            }
        }

        return count;
    }
};
