class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();

        for (auto x : nums) {
            sum += x;
        }

        // If sum is odd, it can't be partitioned into two equal subsets
        if (sum % 2 != 0) return false;

        int s1 = sum / 2;
        vector<vector<bool>> dp(n, vector<bool>(s1 + 1, false));

        // Base case: sum = 0 is always possible
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: first element
        if (nums[0] <= s1)
            dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= s1; j++) {
                bool nt = dp[i - 1][j]; // not take
                bool t = false;
                if (j >= nums[i]) {
                    t = dp[i - 1][j - nums[i]]; // take
                }
                dp[i][j] = nt || t;
            }
        }

        return dp[n - 1][s1];
    }
};
