class Solution {
public:
    int solve(string& text1, string& text2, int index1, int index2, vector<vector<int>>& dp){
        if(index1 < 0 || index2 < 0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];

        // If characters match
        if(text1[index1] == text2[index2]){
            return dp[index1][index2] = 1 + solve(text1, text2, index1-1, index2-1, dp);
        }
        // If characters don't match
        return dp[index1][index2] = max(solve(text1, text2, index1-1, index2, dp), 
                                      solve(text1, text2, index1, index2-1, dp));
    }
    
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(text1, text2, n-1, m-1, dp);
    }
};