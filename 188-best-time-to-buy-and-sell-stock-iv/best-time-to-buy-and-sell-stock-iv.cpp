class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        // dp[index][buy][transactionsLeft]
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        // Bottom-up DP
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {   // fixed: <= instead of >=
                for (int maxt = 1; maxt <= k; maxt++) { // start from 1, since maxt=0 always 0
                    if (buy == 1) {
                        dp[index][buy][maxt] = max(
                            -prices[index] + dp[index + 1][0][maxt],
                            dp[index + 1][1][maxt]
                        );
                    } else {
                        dp[index][buy][maxt] = max(
                            prices[index] + dp[index + 1][1][maxt - 1],
                            dp[index + 1][0][maxt]
                        );
                    }
                }
            }
        }

        return dp[0][1][k]; // start at day 0, allowed to buy, with 2 transactions


    }
};