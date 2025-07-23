class Solution {
  public:
    int solve(vector<int> &wt, vector<int> &val, int w, int n, vector<vector<int>> &dp) {
        if (n == 0 || w == 0) return 0;

        if (dp[n][w] != -1) return dp[n][w];

        if (wt[n - 1] <= w) {
            return dp[n][w] = max(
                val[n - 1] + solve(wt, val, w - wt[n - 1], n - 1, dp),
                solve(wt, val, w, n - 1, dp)
            );
        } else {
            return dp[n][w] = solve(wt, val, w, n - 1, dp);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        // Create a 2D DP table since both 'n' and 'W' vary
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return solve(wt, val, W, n, dp);
    }
};
