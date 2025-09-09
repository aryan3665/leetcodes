// User function Template for C++
class Solution {
  public:
    int countBT(int h) {
        const int MOD = 1e9+7;
        vector<long long> dp(h+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        
        for (int i = 2; i <= h; i++) {
            long long x = (dp[i-1] * dp[i-1]) % MOD;
            long long y = (2LL * dp[i-1] * dp[i-2]) % MOD;
            dp[i] = (x + y) % MOD;
        }
        return (int)dp[h];
    }
};
