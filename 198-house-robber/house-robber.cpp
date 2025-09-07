class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        int dp[105]; // slightly larger to be safe
        dp[n] = 0;
        dp[n+1] = 0; 

        for (int i = n - 1; i >= 0; i--) {
            int skip = dp[i+1];
            int steal = nums[i] + dp[i+2];
            dp[i] = max(steal, skip);
        }

        return dp[0];
    }
};
