class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n=s1.size();
        int m=s2.size();
         vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    // Fill DP table from bottom-up
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j >= 0; j--) {
            if(s1[i] == s2[j]) {
                dp[i][j] = 1 + dp[i+1][j+1];
            } else {
                dp[i][j] = 0;
            }
        }
    }
   //find max element of the dp
   int maxi=0;
   for(int i=0;i<=n;i++){
       for(int j=0;j<=m;j++){
           maxi=max(maxi,dp[i][j]);
       }
   }
   return maxi;
    }
};