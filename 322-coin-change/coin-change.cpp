class Solution {
public:
    int sol(vector<int>& coins, int amount, vector<vector<int>>& dp, int index) {
        if (index == 0) {
            if (amount % coins[0] == 0) return amount / coins[0];
            else return 1e9;  // Impossible case
        }

        if (dp[index][amount] != -1) return dp[index][amount];

        int notTake = sol(coins, amount, dp, index - 1);
        int take = 1e9;
        if (amount >= coins[index]) {
            take = 1 + sol(coins, amount - coins[index], dp, index);
        }

        return dp[index][amount] = min(take, notTake);
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
        int res = sol(coins, amount, dp, n - 1);
        return (res >= 1e9) ? -1 : res;
    }
};
