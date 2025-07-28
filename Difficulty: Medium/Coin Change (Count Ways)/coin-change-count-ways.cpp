class Solution {
public:
   int dp[1001][1001];
    int solve(vector<int>& coins, int sum, int i) {
        if (sum == 0) return 1;
        if (i >= coins.size() || sum < 0) return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        // Don't take the current coin
        int notTake = solve(coins, sum, i + 1);

        // Take the current coin
        int take = solve(coins, sum - coins[i], i);

        return dp[i][sum]=take + notTake;
    }

    int count(vector<int>& coins, int sum) {
        memset(dp,-1,sizeof(dp));
        return solve(coins, sum, 0);
    }
};
