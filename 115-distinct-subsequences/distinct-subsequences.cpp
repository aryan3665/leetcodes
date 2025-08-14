class Solution {
public:
    int dp[1001][1001]; // DP table

    int solve(string &s, string &tgt, int i, int j) {
        // base cases
        if (j == tgt.size()) return 1; // matched whole target
        if (i == s.size()) return 0;   // s ended, but target not matched

        if (dp[i][j] != -1) return dp[i][j];

        if (s[i] == tgt[j]) {
            // include + exclude
            return dp[i][j] = solve(s, tgt, i + 1, j + 1) + solve(s, tgt, i + 1, j);
        }
        // skip current char in s
        return dp[i][j] = solve(s, tgt, i + 1, j);
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
    }
};
