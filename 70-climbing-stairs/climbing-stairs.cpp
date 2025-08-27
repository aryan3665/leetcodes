class Solution {
public:
   int dp[46];
int f(int n){
    if(n<=1)return 1;
    if(dp[n]!=-1)return dp[n];

    int one=f(n-1);
    int two=f(n-2);
    return dp[n]=one+two;
}
    int climbStairs(int n) {
     memset(dp,-1,sizeof(dp));
        return f(n);
    }
};