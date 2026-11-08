class Solution {
public:
    int countServers(vector<vector<int>>& grid) {
        // brute force
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<int> row(n, 0);
        vector<int> col(m, 0);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j]==1)
             {
                        row[i]++;
                        col[j]++;
                    }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                if (grid[i][j] == 1) {
                    if (row[i] >= 2 || col[j] >= 2)
                        ans += 1;
                }
            }
        }

        return ans;
    }
};