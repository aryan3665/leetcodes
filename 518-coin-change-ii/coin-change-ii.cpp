class Solution {
public:
int solve(vector<int>& coins,int index,int amount,vector<vector<int>>&dp){

    //base case
    if(index==0){
        if(amount%coins[0]==0)return 1;
        else{
            return 0;
        }
    }

    if(dp[index][amount]!=-1)return dp[index][amount];
    int notpic=solve(coins,index-1,amount,dp);
    int pic=0;
    if(coins[index]<=amount){
        pic=solve(coins,index,amount-coins[index],dp);
    }
    return dp[index][amount]=notpic+pic;
}
    int change(int amount, vector<int>& coins) {
        //here we can use same coin multiple times
        int n=coins.size();
vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        return solve(coins,n-1,amount,dp);
    }
};