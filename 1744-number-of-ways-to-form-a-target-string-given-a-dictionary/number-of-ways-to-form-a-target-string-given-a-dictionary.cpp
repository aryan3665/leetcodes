class Solution {
public:
    int k, m;
    const int MOD = 1e9 + 7;

    long long fun(vector<string>& words, string& target, int i, int j,  
                  vector<vector<long long>>& freq, vector<vector<long long>>& dp) {
        if (i == m) return 1;     // formed target
        if (j == k) return 0;     // ran out of columns
        
        if (dp[i][j] != -1) return dp[i][j];

        // Option 1: not pick column j
        long long notpic = fun(words, target, i, j+1, freq, dp) % MOD;

        // Option 2: pick from column j (if available chars)
        long long pic = (freq[target[i]-'a'][j] * fun(words, target, i+1, j+1, freq, dp)) % MOD;

        return dp[i][j] = (pic + notpic) % MOD;
    }

    int numWays(vector<string>& words, string target) {
        k = words[0].size();
        int n = words.size();
        m = target.size();

        // precompute frequency table with long long
        vector<vector<long long>> freq(26, vector<long long>(k, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < k; j++) {
                freq[words[i][j] - 'a'][j]++;
            }
        }

        // memo table also long long
        vector<vector<long long>> dp(m+1, vector<long long>(k+1, -1));

        return (int) fun(words, target, 0, 0, freq, dp);
    }
};
