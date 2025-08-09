class Solution {
public:
    // int solve(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp){
    //     if(index1 < 0 || index2 < 0) return 0;
    //     if(dp[index1][index2] != -1) return dp[index1][index2];

    //     // If characters match
    //     if(text1[index1] == text2[index2]){
    //         return dp[index1][index2] = 1 + solve(text1, text2, index1-1, index2-1, dp);
    //     }
    //     // If characters don't match
    //     return dp[index1][index2] = max(solve(text1, text2, index1-1, index2, dp), 
    //                                   solve(text1, text2, index1, index2-1, dp));
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(text1, text2, n-1, m-1, dp);

        // now to use tabulation we will shifting the approch in tabulation 0 means -1, 1 means 0 and n means n-1 and so on 
        int dp[n+1][m+1];
        //base cae when index 1 or index 2 become negative 
        for(int i=0;i<=n;i++){
            dp[i][0]=0;
        }
        for(int j=0;j<=m;j++){
            dp[0][j]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       return dp[n][m]; 
    }
};