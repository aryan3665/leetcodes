// User function template for C++

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    int solve(string &s1, string &s2){
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[n][m];
    }
    
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        // we will ensure we must take common in two strings first them ans will be n+m-lps
     int n=s1.size();
     int m=s2.size();
     int lps=solve(s1,s2);
     return n+m-lps;


    }
};