class Solution {
public:
    int m, n;
    int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};

    pair<bool,int> dfs(vector<vector<int>>& grid, int i, int j) {

        grid[i][j] = 0;   // visited mark

        bool closed = true;
        int cnt = 1;

        if(i == 0 || i == m-1 || j == 0 || j == n-1)
            closed = false;

        for(auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if(ni >= 0 && ni < m && nj >= 0 && nj < n &&
               grid[ni][nj] == 1) {

                auto temp = dfs(grid, ni, nj);
                closed = closed && temp.first;
                cnt += temp.second;
            }
        }

        return {closed, cnt};
    }

    int numEnclaves(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();

        int ans = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(grid[i][j] == 1) {
                    auto res = dfs(grid, i, j);

                    if(res.first)
                        ans += res.second;
                }
            }
        }

        return ans;
    }
};