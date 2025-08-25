class Solution {
public:

    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(), satisfaction.end());
        int n = satisfaction.size();

        // dp[i][time] = max satisfaction from index i with current "time"
        vector<vector<int>> dp(n + 1, vector<int>(n + 2, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int time = n; time >= 1; time--) {
                int not_pick = dp[i + 1][time];
                int pick = satisfaction[i] * time + dp[i + 1][time + 1];
                dp[i][time] = max(pick, not_pick);
            }
        }

        return dp[0][1];  
    }
};
