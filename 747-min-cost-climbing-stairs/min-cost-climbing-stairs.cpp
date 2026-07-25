class Solution {
public:
int dp[1001];
int f(vector<int>& cost,int i){
    if(i>=cost.size())return 0;
    if(dp[i]!=-1)return dp[i];
    //1 step
    int c1=cost[i]+f(cost,i+1);
    //2 step
    int c2=cost[i]+f(cost,i+2);


    return dp[i]=min(c1,c2);



}
    int minCostClimbingStairs(vector<int>& cost) {
       memset(dp,-1,sizeof(dp));
        int c1=f(cost,0);
        int c2=f(cost,1);
        return min(c1,c2);
    }
};