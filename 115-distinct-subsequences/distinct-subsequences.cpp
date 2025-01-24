class Solution {
public:
    vector<unsigned int> dp;
    int numDistinct(string s, string t) {
        int m = s.length() , n = t.length();
        dp.assign(n+1,0);
        //dp
        for(int i=1;i<=m;i++){
            int pre = 1;
            for(int j=1;j<=n;j++){
                int tmp = dp[j];
                if(s[i-1] == t[j-1]){
                    dp[j] += pre;
                }
                pre = tmp;
            }
        }
        return dp[n];
    }
};