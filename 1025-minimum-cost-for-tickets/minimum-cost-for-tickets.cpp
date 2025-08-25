class Solution {
public:
    

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n + 1, 0);  // dp[i] = min cost to cover travel from i to end
        dp[n] = 0;  // base case: no days left → cost 0

        for (int i = n - 1; i >= 0; i--) {
            // 1-day pass
            int cost1 = costs[0] + dp[i + 1];

            // 7-day pass
            int j = i;
            while (j < n && days[j] < days[i] + 7) {
                j++;
            }
            int cost7 = costs[1] + dp[j];

            // 30-day pass
            j = i;
            while (j < n && days[j] < days[i] + 30) {
                j++;
            }
            int cost30 = costs[2] + dp[j];

            dp[i] = min({cost1, cost7, cost30});
        }

        return dp[0];  // min cost starting from first travel day
    }
};

