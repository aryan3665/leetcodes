class Solution {
public:
    vector<int> dp = vector<int>(1e5 + 1, -1);  // Memoization table

    int solve(vector<int>& height, int i) {
        // Base case
        if (i == 0) return 0;

        // Return if already calculated
        if (dp[i] != -1) return dp[i];

        // Option 1: Jump from i-1
        int onestep = solve(height, i - 1) + abs(height[i] - height[i - 1]);

        // Option 2: Jump from i-2 (if possible)
        int twostep = INT_MAX;
        if (i > 1)
            twostep = solve(height, i - 2) + abs(height[i] - height[i - 2]);

        // Store and return min cost
        return dp[i] = min(onestep, twostep);
    }

    int minCost(vector<int>& height) {
        int n = height.size();
        return solve(height, n - 1);
    }
};
