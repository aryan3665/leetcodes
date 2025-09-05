class Solution {
public:
int s(int n,vector<int>&dp){
    if(n==0)return 0;
    if(n<=2)return 1;
    if(dp[n]!=-1)return dp[n];

    return dp[n]=(s(n-1,dp)+s(n-2,dp)+s(n-3,dp));
}
    int tribonacci(int n) {
    vector<int>dp(n+1,-1);
    return s(n,dp);
    }
};