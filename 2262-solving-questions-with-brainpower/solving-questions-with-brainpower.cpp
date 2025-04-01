class Solution {
    long long func(vector<vector<int>>& questions,vector<long long>& dp,int ind,int n){
        if(ind>=n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        long long take=questions[ind][0]+func(questions,dp,ind+questions[ind][1]+1,n);
        long long nottake=func(questions,dp,ind+1,n);
        return dp[ind]=max(take,nottake);
    }
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n=questions.size();
        vector<long long> dp(n,-1);
        return func(questions,dp,0,n);
    }
};