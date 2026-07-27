class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // Agar start ya destination blocked hai
        if(grid[0][0] == 1 || grid[m-1][n-1] == 1)
            return 0;

        // DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting point
        dp[0][0] = 1;

        // DP fill karenge
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // Starting cell already fill hai
                if(i == 0 && j == 0)
                    continue;

                // Agar obstacle hai to yaha koi path nahi aa sakta
                if(grid[i][j] == 1)
                {
                    dp[i][j] = 0;
                    continue;
                }

                int left = 0;
                int up = 0;

                // Left cell exist karta hai
                if(j > 0)
                    left = dp[i][j-1];

                // Upper cell exist karta hai
                if(i > 0)
                    up = dp[i-1][j];

                // Total paths
                dp[i][j] = left + up;
            }
        }

        // Final answer
        return dp[m-1][n-1];
    }
};