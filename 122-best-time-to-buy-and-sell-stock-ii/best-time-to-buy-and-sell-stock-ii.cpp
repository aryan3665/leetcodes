class Solution {
public:
    int solve(vector<int>& prices, int i, bool canBuy, vector<vector<int>>& dp) {
        if (i == prices.size()) return 0;

        if (dp[i][canBuy] != -1) return dp[i][canBuy];

        int profit = 0;
        if (canBuy) {
            // Either buy today or skip
            profit = max(-prices[i] + solve(prices, i+1, false, dp),
                         solve(prices, i+1, true, dp));
        } else {
            // Either sell today or skip
            profit = max(prices[i] + solve(prices, i+1, true, dp),
                         solve(prices, i+1, false, dp));
        }

        return dp[i][canBuy] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(prices, 0, true, dp); // start with "canBuy" = true
    }
};
