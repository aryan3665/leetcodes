class Solution {
public:
int dp[5001][2];//dp of day and buy bool

int solve(vector<int>& prices,int day,bool buy){
    if(day>=prices.size())return 0;
    int profit=0;

    if(dp[day][buy]!=-1)return dp[day][buy];
    if(buy){
        int take=solve(prices,day+1,false)-prices[day];
        int nottake=solve(prices,day+1,true);

        profit=max(profit ,max(take,nottake));
    }
    else{
        //sell
        int sell=prices[day]+solve(prices,day+2,true);
        int notsell=solve(prices,day+1,false);
        profit=max(profit,max(sell,notsell));
    }

    return dp[day][buy]=profit;
}
    int maxProfit(vector<int>& prices) {
        memset(dp,-1,sizeof(dp));
        bool buy=true;
        return solve(prices,0,true);
    }
};