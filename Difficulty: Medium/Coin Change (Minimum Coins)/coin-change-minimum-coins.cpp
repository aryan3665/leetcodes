class Solution {
public:
    int solve(int i, int target, vector<int>& coins, vector<vector<int>>& dp) {
        const int INF = 1e9;
        
        // Base case
        if (i == 0) {
            if (target % coins[0] == 0) return target / coins[0];
            return INF; // not possible
        }

        if (dp[i][target] != -1) return dp[i][target];

        // Not take
        int notTake = solve(i - 1, target, coins, dp);

        // Take
        int take = INF;
        if (target >= coins[i]) {
            take = 1 + solve(i, target - coins[i], coins, dp);
        }

        return dp[i][target] = min(take, notTake);
    }

    int minCoins(vector<int>& coins, int sum) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(sum + 1, -1));

        int ans = solve(n - 1, sum, coins, dp);

        return (ans >= 1e9 ? -1 : ans);
    }
};
