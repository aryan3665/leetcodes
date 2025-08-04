class Solution {
  public:
  int solve(int W,vector<int>&val,vector<int>&wt,int index,vector<vector<int>>&dp){
    if(index == 0){
    if(wt[0] <= W) return val[0];
    else return 0;
}


if(dp[index][W]!=-1)return dp[index][W];
      int notpick=solve(W,val,wt,index-1,dp);
      int pick=INT_MIN;
      if(W>=wt[index]){
          pick=val[index]+solve(W-wt[index],val,wt,index-1,dp);
      }
      return dp[index][W]=max(pick,notpick);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=wt.size();
        vector<vector<int>>dp(n,vector<int>(W+1,-1));
        
        return solve(W,val,wt,n-1,dp);
    }
};