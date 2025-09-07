class Solution {
public:
int dp[101];
int rob1(vector<int>&nums,int i,int end){
    if(i>end)return 0;
    if(dp[i]!=-1)return dp[i];


    int yes=nums[i]+rob1(nums,i+2,end);
    int no=rob1(nums,i+1,end);
    return dp[i]=max(yes,no);
}
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];
        //steal in oth index house
        memset(dp,-1,sizeof(dp));
        int case1=rob1(nums,0,n-2);
        //skip oth index house
         memset(dp,-1,sizeof(dp));
        int case2=rob1(nums,1,n-1);


        return max(case1,case2); 
    }
};