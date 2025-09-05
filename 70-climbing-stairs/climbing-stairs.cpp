class Solution {
public:
    int climbStairs(int n) {
       if(n<=1)return 1;
       vector<int>dp(n+1);
       dp[0]=1;
       int n1=1;
       int n2=1;
       int n3;
       dp[1]=1;

       for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
        n3=n2+n1;
        n1=n2;
        n2=n3;
       }
    //    return dp[n];
       return n3;
    }
};