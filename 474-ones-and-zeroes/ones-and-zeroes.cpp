class Solution {
public:
    int countChar(const string &s, char c) {
        return count(s.begin(), s.end(), c);
    }

    int solve(int index, vector<string>& strs, int m, int n, vector<vector<vector<int>>>& dp) {
        if (index == strs.size()) return 0;
        if (dp[index][m][n] != -1) return dp[index][m][n];

        int zero = countChar(strs[index], '0');
        int one = countChar(strs[index], '1');

        // not take
        int notTake = solve(index + 1, strs, m, n, dp);

        // take if possible
        int take = 0;
        if (m >= zero && n >= one)
            take = 1 + solve(index + 1, strs, m - zero, n - one, dp);

        return dp[index][m][n] = max(take, notTake);
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int size = strs.size();
        vector<vector<vector<int>>> dp(size + 1,
            vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return solve(0, strs, m, n, dp);
    }
};
