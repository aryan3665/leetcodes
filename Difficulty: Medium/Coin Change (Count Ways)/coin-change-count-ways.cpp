class Solution {
public:
   int dp[1001][1001];
    int solve(vector<int>& coins, int sum, int i) {
        if (sum == 0) return 1;
        if (i >= coins.size() || sum < 0) return 0;
        if(dp[i][sum]!=-1)return dp[i][sum];
        // Don't take the current coin
        int notTake = solve(coins, sum, i + 1);

        // Take the current coin
        int take = solve(coins, sum - coins[i], i);

        return dp[i][sum]=take + notTake;
    }

    int count(vector<int>& coins, int sum) {
        int n=coins.size();
        vector<vector<int>>t(n+1,vector<int>(sum+1));
        for(int i=0;i<=n;i++){
            t[i][0]=1;
        }
        //base case 2
        for(int i=0;i<=sum;i++){
            t[n][i]=0;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int s=1;s<=sum;s++){
                int notTake = t[i+1][s];

        // Take the current coin
        int take=0;
        if(s>=coins[i]){
        take = t[i][s-coins[i]];
        }

      t[i][s]=take + notTake; 
            }
        }
        
        return t[0][sum];
    }
};
