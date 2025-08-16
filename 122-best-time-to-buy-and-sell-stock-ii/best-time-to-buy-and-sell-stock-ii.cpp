class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int dp[n + 1][2];

        // Base case: when day = n (no days left)
        dp[n][0] = 0;
        dp[n][1] = 0;

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;
                if (buy == 1) {
                    // Either buy today or skip
                    profit = max(-prices[i] + dp[i + 1][0], dp[i + 1][1]);
                } else {
                    // Either sell today or skip
                    profit = max(prices[i] + dp[i + 1][1], dp[i + 1][0]);
                }
                dp[i][buy] = profit; 
            }
        }

        return dp[0][1];
    }
};
