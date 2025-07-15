class Solution {
public:
    int r, c;
    int row[4] = {0, 0, -1, 1};
    int col[4] = {-1, 1, 0, 0};

    bool isvalid(int i, int j) {
        return (i >= 0 && j >= 0 && i < r && j < c);
    }

    int orangesRotting(vector<vector<int>>& mat) {
        r = mat.size();
        c = mat[0].size();
        queue<pair<int, int>> q;

        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 2) {
                    q.push({i, j});
                }
            }
        }

        int t = 0;

        while (!q.empty()) {
            int n = q.size();
            bool changed = false;

            while (n--) {
                int x = q.front().first;
                int y = q.front().second;
                q.pop();

                for (int k = 0; k < 4; k++) {
                    int nx = x + row[k];
                    int ny = y + col[k];
                    if (isvalid(nx, ny) && mat[nx][ny] == 1) {
                        mat[nx][ny] = 2;
                        q.push({nx, ny});
                        changed = true;
                    }
                }
            }

            if (changed) t++;  // Only increment time if at least one orange got rotten
        }

        // Final check for any remaining fresh orange
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (mat[i][j] == 1) {
                    return -1;
                }
            }
        }

        return t;
    }
};
