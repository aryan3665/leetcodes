class Solution {
public:
    const int MOD = 1e9 + 7;

    int numWays(vector<string>& words, string target) {
        int k = words[0].size();
        int n = words.size();
        int m = target.size();

        // precompute frequency table
        vector<vector<long long>> freq(26, vector<long long>(k, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                freq[words[i][j] - 'a'][j]++;
            }
        }

        // dp[i][j] = number of ways to form target[i:] using columns j..k-1
        vector<vector<long long>> dp(m+1, vector<long long>(k+1, 0));

        // base case: if we've matched whole target, 1 way
        for (int j = 0; j <= k; j++) dp[m][j] = 1;

        // fill dp from bottom-up
        for (int i = m-1; i >= 0; i--) {
            for (int j = k-1; j >= 0; j--) {
                // option 1: not pick from column j
                long long notpic = dp[i][j+1] % MOD;

                // option 2: pick from column j (if matching char available)
                long long pic = (freq[target[i]-'a'][j] * dp[i+1][j+1]) % MOD;

                dp[i][j] = (pic + notpic) % MOD;
            }
        }

        return (int) dp[0][0];
    }
};
