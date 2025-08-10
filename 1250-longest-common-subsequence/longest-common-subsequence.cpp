class Solution {
public:
    // int solve(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp){
    //     if(index1 ==text1.size() || index2 ==text2.size()) return 0;
    //     if(dp[index1][index2] != -1) return dp[index1][index2];

    //     // If characters match
    //     if(text1[index1] == text2[index2]){
    //         return dp[index1][index2] = 1 + solve(text1, text2, index1+1, index2+1, dp);
    //     }
    //     // If characters don't match
    //     return dp[index1][index2] = max(solve(text1, text2, index1+1, index2, dp), 
    //                                   solve(text1, text2, index1, index2+1, dp));
    // }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        // return solve(text1, text2, 0, 0, dp);
        vector<vector<int>>dp(n+1,vector<int>(m+1));
        for(int i=0;i<=text2.size();i++){
            dp[n][i]=0;
        }
        for(int j=0;j<=text1.size();j++){
            dp[j][m]=0;
        }

        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j]=1+dp[i+1][j+1];
                }
                else{
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }

       int max_val = INT_MIN; // Initialize with smallest possible value
for(int i = 0; i < dp.size(); i++) {
    for(int j = 0; j < dp[0].size(); j++) {
        if(dp[i][j] > max_val) {
            max_val = dp[i][j];
        }
    }
}

return max_val;
    }
};