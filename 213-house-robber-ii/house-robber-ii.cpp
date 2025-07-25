class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];
        if (n == 2) return max(nums[0], nums[1]);

        // ---- CASE 1: Rob from house 0 to n-2 (exclude last house) ----
        vector<int> dp1(n, 0);
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n - 1; i++) {
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]);
        }
        int case1 = dp1[n - 2];

        // ---- CASE 2: Rob from house 1 to n-1 (exclude first house) ----
        vector<int> dp2(n, 0);
        dp2[1] = nums[1];
        for (int i = 2; i < n; i++) {
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i]);
        }
        int case2 = dp2[n - 1];

        return max(case1, case2);
    }
};
