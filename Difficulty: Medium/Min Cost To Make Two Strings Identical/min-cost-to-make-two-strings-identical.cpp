class Solution {
public:

    int f(string &s1, string &s2, int costS1, int costS2,
          int i, int j, vector<vector<int>> &dp) {

        // Base case
        if (i == s1.size()) {
            return (s2.size() - j) * costS2;
        }

        if (j == s2.size()) {
            return (s1.size() - i) * costS1;
        }

        // Already calculated
        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        // Characters same
        if (s1[i] == s2[j]) {
            return dp[i][j] =
                f(s1, s2, costS1, costS2, i + 1, j + 1, dp);
        }

        // Delete s1[i]
        int cost1 = costS1 +
            f(s1, s2, costS1, costS2, i + 1, j, dp);

        // Delete s2[j]
        int cost2 = costS2 +
            f(s1, s2, costS1, costS2, i, j + 1, dp);

        return dp[i][j] = min(cost1, cost2);
    }

    int findMinCost(string &s1, string &s2, int costS1, int costS2) {

        int n = s1.size();
        int m = s2.size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return f(s1, s2, costS1, costS2, 0, 0, dp);
    }
};