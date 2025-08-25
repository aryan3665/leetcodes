class Solution {
public:
    vector<vector<int>> dp;

    bool solve(string &s, string &t, int i, int j) {
        // base cases
        if (i == s.size()) return true;   // matched all of s
        if (j == t.size()) return false;  // ran out of t

        // memo check
        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;
        if (s[i] == t[j]) {
            // option 1: take match
            ans = solve(s, t, i + 1, j + 1);
        }
        // option 2: skip t[j]
        if (!ans) ans = solve(s, t, i, j + 1);

        return dp[i][j] = ans;
    }

    bool isSubsequence(string s, string t) {
        dp.assign(s.size(), vector<int>(t.size(), -1));
        return solve(s, t, 0, 0);
    }
};
