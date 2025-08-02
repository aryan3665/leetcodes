class Solution {
  public:
  int dp[1001][1001];
  int solve(vector<int>&arr,int i,int n,int target){
      
  
     if(i==n){
         if(target==0)return 1;
         else{
             return 0;
         }
     }
     if(dp[i][target]!=-1)return dp[i][target];
    
    int take=solve(arr,i+1,n,target-arr[i]);
     int nottake=solve(arr,i+1,n,target);
     return dp[i][target]=take+nottake;
  }
    int perfectSum(vector<int>& arr, int target) {
        // code here
        memset(dp,-1,sizeof(dp));
        
        return solve(arr,0,arr.size(),target);
    }
}; 