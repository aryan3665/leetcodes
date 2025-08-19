class Solution {
public:
    int solve(int index, int buy, int maxt, vector<vector<vector<int>>>& dp,
              vector<int>& prices) {
        if (maxt == 0)
            return 0;
        if (index == prices.size())
            return 0;
        if (dp[index][buy][maxt] != -1)
            return dp[index][buy][maxt];

        if (buy) {
            return dp[index][buy][maxt] = max(
                       -prices[index] + solve(index + 1, 0, maxt, dp, prices),
                       solve(index + 1, 1, maxt, dp, prices));
        } else {
            return dp[index][buy][maxt] =
                       max(prices[index] +
                               solve(index + 1, 1, maxt - 1, dp, prices),
                           solve(index + 1, 0, maxt, dp, prices));
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[index][buy][transactionsLeft]
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(3, 0)));

        // Bottom-up DP
        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {   // fixed: <= instead of >=
                for (int maxt = 1; maxt <= 2; maxt++) { // start from 1, since maxt=0 always 0
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

        return dp[0][1][2]; // start at day 0, allowed to buy, with 2 transactions
    }
};

