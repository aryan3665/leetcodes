class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101];

    int solve(vector<vector<int>>& obstacleGrid, int i, int j) {
        if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1) return 0; // obstacle = 1
        if (i == 0 && j == 0) return obstacleGrid[0][0] == 1 ? 0 : 1;
        if (i < 0 || j < 0) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = (solve(obstacleGrid, i - 1, j) + solve(obstacleGrid, i, j - 1));
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        memset(dp, -1, sizeof(dp));
        return solve(obstacleGrid, m - 1, n - 1);
    }
};
