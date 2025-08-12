class Solution {
public:
    int MOD = 1e9 + 7;

    int count(vector<vector<int>>& dp, int n, int x, int ind) {
        if (n==0) return 1;
        if (ind==0) return 0;
        if (dp[n][ind]!=-1) return dp[n][ind];

        int notPick = count(dp,n,x,ind-1);
        int pick = 0;
        long long power = pow(ind, x);
        if (power<=n) pick=count(dp,n-(int)power,x,ind-1);

        return dp[n][ind] = ((long long)pick+notPick) % MOD;
    }

    int numberOfWays(int n, int x) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return count(dp, n, x, n);
    }
};