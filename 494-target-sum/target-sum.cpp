class Solution {
public:
int find(vector<int>&nums,int target){
     int n = nums.size();
        const int MOD = 1e9 + 7;
        
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        // Base case
        if (nums[0] == 0) {
            dp[0][0] = 2; // pick or not pick
        } else {
            dp[0][0] = 1; // not pick
            if (nums[0] <= target)
                dp[0][nums[0]] = 1; // pick
        }
        
        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= target; j++) {
                int notPick = dp[i-1][j];
                int pick = 0;
                if (nums[i] <= j)
                    pick = dp[i-1][j - nums[i]];
                dp[i][j] = (pick + notPick) % MOD;
            }
        }
        
        return dp[n-1][target];
}
int countway(int n,vector<int>& nums,int target){
    int total=0;
    for(int i=0;i<n;i++)total+=nums[i];
    if((total-target)<0||(total-target)%2)return false;
    return find(nums,(total-target)/2);
}
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        return countway(n,nums,target);
    }
};