class Solution {
  public:
  
    int findSum(int n) {
       vector<int>dp(n+1);
       dp[0]=0;
       dp[1]=1;
       for(int i=2;i<=n;i++){
           dp[i]=i+dp[i-1];
       }
       return dp[n];
    }
};
