class Solution {
public:
    vector<vector<int>> dp;  // Declare dp as a member of the class

    bool solve(vector<int>& arr, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0) return false;

        if (dp[sum][n] != -1) return dp[sum][n];

        if (arr[n - 1] <= sum) {
            return dp[sum][n] = solve(arr, sum - arr[n - 1], n - 1) || solve(arr, sum, n - 1);
        } else {
            return dp[sum][n] = solve(arr, sum, n - 1);
        }
    }

    bool isSubsetSum(vector<int>& arr, int sum) {
        int n = arr.size();
        dp = vector<vector<int>>(sum + 1, vector<int>(n + 1, -1));  // Initialize dp

        return solve(arr, sum, n);
    }
};
