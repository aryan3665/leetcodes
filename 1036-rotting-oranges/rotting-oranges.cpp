class Solution {
public:
    bool valid(int i, int j, int r, int c) {
        return (i >= 0 && i < r && j >= 0 && j < c);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int row[4] = {-1, 1, 0, 0};
        int col[4] = {0, 0, -1, 1};

        int r = grid.size();
        int c = grid[0].size();
        queue<pair<int, int>> q;

        // Push all bad oranges
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int time = 0;

        while (!q.empty()) {
           
            int curr_roten = q.size();
             bool spread = false;
           

            while (curr_roten--) {
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int ni = i + row[k];
                    int nj = j + col[k];
                    if (valid(ni, nj, r, c) && grid[ni][nj] == 1) {
                        grid[ni][nj] = 2;
                         spread = true;
                        q.push({ni, nj});
                    }
                }
            }
            if (spread) time++;
        }

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return time;
    }
};