class Solution {
public:
    int dp[1001][1001];
    int solve(string &s1, string &s2, int index1, int index2) {
        // base case
        if(index1 < 0 || index2 < 0) return 0;
        if(dp[index1][index2] != -1) return dp[index1][index2];

        // if the char matches
        if(s1[index1] == s2[index2]) {
            return dp[index1][index2] = 1 + solve(s1, s2, index1-1, index2-1);
        }
        // if char not match
        return dp[index1][index2] = max(solve(s1, s2, index1-1, index2), solve(s1, s2, index1, index2-1));
    }
    
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s.begin(), s.end());
        string s2 = s;
        int n = s1.size();
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, n-1, n-1);
    }
};