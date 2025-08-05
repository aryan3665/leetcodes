class Solution {
public:
    bool solve(vector<int>& nums, int sum) {
        int n = nums.size();
        bool dp[n][sum + 1];

        // Initialize all values to false
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= sum; j++) {
                dp[i][j] = false;
            }
        }

        // Base case: sum 0 is always possible (empty subset)
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }

        // Base case: first element can make sum nums[0] if it's <= sum
        if (nums[0] <= sum) {
            dp[0][nums[0]] = true;
        }

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= sum; j++) {
                bool notPick = dp[i - 1][j];
                bool pick = false;
                if (j >= nums[i]) {
                    pick = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = notPick || pick;
            }
        }

        return dp[n - 1][sum];
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto it : nums) {
            sum += it;
        }
        if (sum % 2 != 0)
            return false;
        int n = nums.size();

        return solve(nums, sum / 2);
    }
};