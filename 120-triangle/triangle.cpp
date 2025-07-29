// class Solution {
// public:
// // /int solve(int i,int j,vector<vector<int>>& triangle, vector<vector<int>>&dp,int n){
//     if(i==n-1) return triangle[i][j];
//     if(dp[i][j]!=-1)return dp[i][j];
//     int down=triangle[i][j]+solve(i+1,j,triangle,dp,n);
//     int corner=triangle[i][j]+solve(i+1,j+1,triangle,dp,n);
//     return dp[i][j]=min(down,corner);
// }
    class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));  // Correct initialization

        // Initialize last row of DP
        for(int j = 0; j < n; j++) {
            dp[n-1][j] = triangle[n-1][j];
        }

        // Build the DP table from bottom to top
        for(int i = n - 2; i >= 0; i--) {
            for(int j = 0; j <= i; j++) {
                int down = triangle[i][j] + dp[i+1][j];
                int corner = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, corner);
            }
        }

        return dp[0][0];
    }
};
