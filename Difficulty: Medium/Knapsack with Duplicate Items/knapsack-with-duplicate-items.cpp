class Solution {
  public:
    int solve(vector<int>& wt, vector<int>& val, int index, int capacity, vector<vector<int>>& dp) {
        if (index == 0) {
            return (capacity / wt[0]) * val[0];
        }
        if (dp[index][capacity] != -1) return dp[index][capacity];
        
        int notpic = solve(wt, val, index - 1, capacity, dp);
        int pic = 0;
        if (wt[index] <= capacity) {
            // infinite supply available, so index remains same
            pic = val[index] + solve(wt, val, index, capacity - wt[index], dp);
        }
        return dp[index][capacity] = max(notpic, pic);
    }

    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return solve(wt, val, n - 1, capacity, dp);
    }
};
