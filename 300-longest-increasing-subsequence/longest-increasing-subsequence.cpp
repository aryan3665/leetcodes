class Solution {
public:
    int solve(vector<int>& nums, int i, int prev, vector<vector<int>>& dp) {
        if (i == nums.size()) return 0;

        if (dp[i][prev + 1] != -1) return dp[i][prev + 1];

        int nottake = solve(nums, i + 1, prev, dp);

        int take = 0;
        if (prev == -1 || nums[prev] < nums[i]) {
            take = 1 + solve(nums, i + 1, i, dp);
        }

        return dp[i][prev + 1] = max(take, nottake);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        // dp[i][prev+1], prev = -1 → index 0
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return solve(nums, 0, -1, dp);
    }
};
