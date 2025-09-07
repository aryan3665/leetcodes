class Solution {
public:
    long long solve(vector<int>& nums, int i, bool s, vector<vector<long long>>& dp) {
        if (i == nums.size()) return 0;
        if (dp[i][s] != -1) return dp[i][s];

        long long nt = solve(nums, i + 1, s, dp); // skip
        long long take;
        if (s == 0) {
            // add this element
            take = nums[i] + solve(nums, i + 1, 1, dp);
        } else {
            // subtract this element
            take = -nums[i] + solve(nums, i + 1, 0, dp);
        }

        return dp[i][s] = max(take, nt);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> dp(n, vector<long long>(2, -1));
        return solve(nums, 0, 0, dp); // start with "add"
    }
};
