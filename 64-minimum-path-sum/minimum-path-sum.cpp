class Solution {
public:
//     int dp[201][201];
// #define INF 1e9

// int solve(vector<vector<int>>& grid, int i, int j) {
//     if (i == 0 && j == 0) return grid[0][0];
//     if (i < 0 || j < 0) return INF;
//     if (dp[i][j] != -1) return dp[i][j];

//     int up = grid[i][j] + solve(grid, i - 1, j);
//     int left = grid[i][j] + solve(grid, i, j - 1);
//     return dp[i][j] = min(up, left);
// }



    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
     int dp[m][n];
     for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(i==0&&j==0)dp[0][0]=grid[0][0];

            else{
                int up=INT_MAX;
                int left=INT_MAX;

                if(i>0){
                    up=grid[i][j]+dp[i-1][j];

                }
                if(j>0){
                    left=grid[i][j]+dp[i][j-1];
                }
                dp[i][j]=min(up,left);
            }
        }
     }

     return dp[m-1][n-1];
    }
};