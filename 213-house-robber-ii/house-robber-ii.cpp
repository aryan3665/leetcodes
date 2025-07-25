class Solution {
public:
    int dp[101];

    int robLinear(vector<int>& nums, int start, int end) {
        memset(dp, -1, sizeof(dp));  // Reset dp for each call

        return rob1(nums, start, end);
    }

    int rob1(vector<int>& nums, int i, int end) {
        if (i > end)
            return 0;

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i] + rob1(nums, i + 2, end),
                           rob1(nums, i + 1, end));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        // Case 1: Exclude last house
        int case1 = robLinear(nums, 0, n - 2);
        // Case 2: Exclude first house
        int case2 = robLinear(nums, 1, n - 1);

        return max(case1, case2);
    }
};
