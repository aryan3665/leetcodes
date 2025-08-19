class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        
        // next[buy][transactionsLeft], curr[buy][transactionsLeft]
        vector<vector<int>> next(2, vector<int>(3, 0)), curr(2, vector<int>(3, 0));

        for (int index = n - 1; index >= 0; index--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int maxt = 1; maxt <= 2; maxt++) {
                    if (buy == 1) {
                        curr[buy][maxt] = max(
                            -prices[index] + next[0][maxt],
                            next[1][maxt]
                        );
                    } else {
                        curr[buy][maxt] = max(
                            prices[index] + next[1][maxt - 1],
                            next[0][maxt]
                        );
                    }
                }
            }
            next = curr; // update for the next iteration
        }

        return next[1][2]; // starting at day 0, buy=1, with 2 transactions
    }
};
