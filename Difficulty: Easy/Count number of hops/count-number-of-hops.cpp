class Solution {
  public:
    int mod = 1e9 + 7;
   

    int countWays(int n) {
        vector<int> dp(n + 1);
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
        }
        return dp[n];
        
    }
};
