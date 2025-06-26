class Solution {
public:
    int r, c;
    int row[4] = {-1, 1, 0, 0};
    int col[4] = {0, 0, -1, 1};
    bool valid(int i, int j) { return (i >= 0 && i < r && j >= 0 & j < c); }
    int numIslands(vector<vector<char>>& grid) {

        r = grid.size();
        c = grid[0].size();
        queue<pair<int, int>> q;
        int count = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == '1') {
                    count++;
                    // make all L connected to this to 0
                    q.push({i, j});
                    grid[i][j] = '0';

                    while (!q.empty()) {
                        int new_i = q.front().first;
                        int new_j = q.front().second;
                        q.pop();
                        // now check 8 directions and make 1 to 0
                        for (int k = 0; k < 4; k++) {
                            if (valid(new_i + row[k], new_j + col[k]) &&
                                grid[new_i + row[k]][new_j + col[k]] == '1') {
                                grid[new_i + row[k]][new_j + col[k]] = '0';
                                q.push({new_i + row[k], new_j + col[k]});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};