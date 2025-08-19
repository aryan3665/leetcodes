class Solution {
public:
   int dp[1001][1001];
    int solve(vector<int>& coins, int sum, int i) {
        if (sum == 0) return 1;
        if (i >= coins.size() || sum < 0) return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        // Don't take the current coin
        int notTake = solve(coins, sum, i + 1);

        // Take the current coin
        int take = solve(coins, sum - coins[i], i);

        return dp[i][sum]=take + notTake;
    }


    int count(vector<int>& coins, int sum) {
        int n = coins.size();

        // dp[index][target] = number of ways
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, 0));

        // Base case: if target = 0 → 1 way (choose nothing)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        for (int index = n - 1; index >= 0; index--) {
            for (int s = 1; s <= sum; s++) {
                // Don't take the current coin
                int notTake = dp[index + 1][s];

                // Take the current coin (unlimited use allowed → stay at index)
                int take = 0;
                if (s >= coins[index]) {
                    take = dp[index][s - coins[index]];
                }

                dp[index][s] = take + notTake;
            }
        }

        return dp[0][sum];
    }
};

