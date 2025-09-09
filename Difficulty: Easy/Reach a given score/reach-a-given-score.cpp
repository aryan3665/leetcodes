class Solution {
  public:
    vector<int> coins = {3, 5, 10};

    long long solve(int idx, long long n, vector<vector<long long>>& dp) {
        if (n == 0) return 1;   // found valid way
        if (idx >= coins.size() || n < 0) return 0;

        if (dp[idx][n] != -1) return dp[idx][n];

        // Choice: pick the coin (stay at same idx since unlimited supply)
        long long pick = solve(idx, n - coins[idx], dp);

        // Or skip this coin (move to next index)
        long long skip = solve(idx + 1, n, dp);

        return dp[idx][n] = pick + skip;
    }

    long long int count(long long int n) {
        vector<vector<long long>> dp(3, vector<long long>(n+1, -1));
        return solve(0, n, dp);
    }
};
