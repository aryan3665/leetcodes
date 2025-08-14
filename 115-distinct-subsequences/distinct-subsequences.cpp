#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size(), m = t.size();
        vector<vector<unsigned long long>> dp(n + 1, vector<unsigned long long>(m + 1, 0));

        // Base Case 1: If `t` is empty, there's 1 way (delete all `s`)
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }

        // Base Case 2: If `s` is empty but `t` isn't → 0 ways
        for (int j = 1; j <= m; j++) {
            dp[0][j] = 0;
        }

        // Fill DP table
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }

        return dp[n][m];
    }
};