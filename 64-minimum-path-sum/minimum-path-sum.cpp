class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        // DP table
        vector<vector<int>> dp(m, vector<int>(n, 0));

        // Starting cell
        dp[0][0] = grid[0][0];

        // Puri DP table fill karenge
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                // Starting cell already fill hai
                if(i == 0 && j == 0)
                    continue;

                int left = INT_MAX;
                int up = INT_MAX;

                // Agar left exist karta hai
                if(j > 0)
                    left = dp[i][j-1];

                // Agar upper cell exist karta hai
                if(i > 0)
                    up = dp[i-1][j];

                // Current cell ki value add kar do
                dp[i][j] = grid[i][j] + min(left, up);
            }
        }

        // Destination ka minimum path sum
        return dp[m-1][n-1];
    }
};