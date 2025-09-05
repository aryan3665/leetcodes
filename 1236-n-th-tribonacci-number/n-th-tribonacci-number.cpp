class Solution {
public:
    int tribonacci(int n) {
        // Handle edge cases where n is too small for our loop
        if (n == 0) return 0;
        if (n <= 2) return 1;

        // 1. Create a DP table (an array) of size n+1
        vector<int> dp(n + 1);

        // 2. Initialize the known base cases (the "bottom")
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = 1;

        // 3. Loop from the first unknown value (3) up to the top (n)
        for (int i = 3; i <= n; i++) {
            // The recurrence relation is the same as the recursive step!
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }

        // 4. The answer for the main problem is at the "top" of the table
        return dp[n];
    }
};