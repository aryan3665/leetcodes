class Solution {
public:
    bool hamming(string& a, string& b) {
        if (a.length() != b.length()) {
            return false;
        }
        int count = 0;
        for (int i = 0; i < a.length(); i++) {
            if (a[i] != b[i]) {
                count++;
            }
            if (count > 1) {
                return false;
            }
        }
        return true;
    }
    int solve(int curr, int prev, vector<string>& words, vector<int>& groups
     ,vector<vector<int>>& dp) {
        if (curr == groups.size()) {
            return 0;
        }
        if(dp[curr][prev+1]!=-1){
            return dp[curr][prev+1];
        }
        int take = 0;
        if (prev == -1 || (groups[curr] != groups[prev] &&
                           (hamming(words[prev], words[curr])))) {
            take = 1 + solve(curr + 1, curr, words, groups,dp);
        }
        int nottake = solve(curr + 1, prev, words, groups,dp);
        return dp[curr][prev+1] = max(take, nottake);
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words,
                                                vector<int>& groups) {
        int n = words.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        int a = solve(0, -1, words, groups,dp);
        vector<string> temp;
        int curr = 0 , prev = -1;
        while(curr < n){
             int take = 0;
              if (prev == -1 || (groups[curr] != groups[prev] &&
                           (hamming(words[prev], words[curr])))){
                            take = 1 + dp[curr+1][curr+1];
                           }
              int nottake = dp[curr+1][prev+1];
              if(take >= nottake && a > 0){
                  temp.push_back(words[curr]);
                  a--;
                  prev = curr;
              }
              curr++;
        }
        return temp;
    }
};