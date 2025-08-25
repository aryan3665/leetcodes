class Solution {
public:
int dp[501][501];
int solve(vector<int>& satisfaction,int t,int i){
    if(i>=satisfaction.size())return 0;

    if(dp[i][t]!=-1)return dp[i][t];
    //pick not_pick
    int not_pic=0+solve(satisfaction,t,i+1);
    int pick=(satisfaction[i]*t)+solve(satisfaction,t+1,i+1);

    return dp[i][t]=max(pick,not_pic);

}
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        memset(dp,-1,sizeof(dp));
        return solve(satisfaction,1,0);//time,index
    }
};