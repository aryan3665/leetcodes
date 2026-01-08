class Solution {
public:

int dp[1001][1001];
 bool solve(string &s,int i,int j){
if(i>=j)return true;

if(dp[i][j]!=-1){
    return dp[i][j];
}


if(s[i]==s[j]){
    return dp[i][j]=solve(s,i+1,j-1);
}

return dp[i][j]=false;
 }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxlen=INT_MIN;
        memset(dp,-1,sizeof(dp));
        int sp=-1;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(solve(s,i,j)==true){
                  if(j-i+1>maxlen){
                    maxlen=j-i+1;
                    sp=i;
                  }
                
                }
            }
        }

        return s.substr(sp,maxlen);
    }
};