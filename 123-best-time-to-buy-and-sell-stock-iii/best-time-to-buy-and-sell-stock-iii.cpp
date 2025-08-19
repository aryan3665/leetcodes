class Solution {
public:
    int solve(int index, int buy, int maxt, vector<vector<vector<int>>>& dp, vector<int>& prices) {
        if (maxt == 0) return 0;
        if (index == prices.size()) return 0;
        if (dp[index][buy][maxt] != -1) return dp[index][buy][maxt];

        if (buy) {
            return dp[index][buy][maxt] = max(
                -prices[index] + solve(index + 1, 0, maxt, dp, prices),
                solve(index + 1, 1, maxt, dp, prices)
            );
        } else {
            return dp[index][buy][maxt] = max(
                prices[index] + solve(index + 1, 1, maxt - 1, dp, prices),
                solve(index + 1, 0, maxt, dp, prices)
            );
        }
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        // dp[index][buy][transactionsLeft]
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3, -1)));
        return solve(0, 1, 2, dp, prices);
    }
};
