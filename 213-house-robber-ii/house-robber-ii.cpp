class Solution {
public:
    int dp[101];

    int rob1(vector<int>& nums, int i, int end) {
        if (i >end) return 0; // Fix: use i > end to allow end to be included

        if (dp[i] != -1)
            return dp[i];

        return dp[i] = max(nums[i] + rob1(nums, i + 2, end),
                           rob1(nums, i + 1, end));
    }

    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // Case 1: Include first house, exclude last
        memset(dp, -1, sizeof(dp));
        int case1 = rob1(nums, 0, n - 2);

        // Case 2: Exclude first house, include last
        memset(dp, -1, sizeof(dp));
        int case2 = rob1(nums, 1, n - 1);

        return max(case1, case2);
    }
};
