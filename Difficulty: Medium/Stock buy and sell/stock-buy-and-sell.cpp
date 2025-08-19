class Solution {
public:
    int f(int i, bool buy, vector<int> &arr, vector<vector<int>> &dp) {
        // base case
        if (i == arr.size()) return 0;

        if (dp[i][buy] != -1) return dp[i][buy];

        if (buy) {
            // choice: buy or skip
            int take = -arr[i] + f(i + 1, 0, arr, dp);
            int skip = f(i + 1, 1, arr, dp);
            return dp[i][buy] = max(take, skip);
        } else {
            // choice: sell or skip
            int sell = arr[i] + f(i + 1, 1, arr, dp);
            int skip = f(i + 1, 0, arr, dp);
            return dp[i][buy] = max(sell, skip);
        }
    }

    int stockBuySell(vector<int> &arr) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(2, -1));
        return f(0, 1, arr, dp); // start at index 0, allowed to buy
    }
};
