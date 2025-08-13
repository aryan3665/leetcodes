class Solution {
public:
int dp[501][501];
int solve(string &s1,string&s2,int index1,int index2){
    if(index1<0||index2<0)return 0;
    if(dp[index1][index2]!=-1)return dp[index1][index2];
    //if both char match
    if(s1[index1]==s2[index2]){
        return dp[index1][index2]=1+solve(s1,s2,index1-1,index2-1);
    }
    return dp[index1][index2]=max(solve(s1,s2,index1-1,index2),solve(s1,s2,index1,index2-1));
}
    int minInsertions(string s) {
        //the approch is very simple we have to keep longest palindromic subsequence intact and the ans min step =totalk length of string -lps length for example in string abcaa the lps is of length 3 (aaa) we have min 2 operatoion required to make it palindrom a a a -->  abcacba is palindrom so we just have to find lps nothing big needed
        string s1=s;
        string s2;
        reverse(s.begin(),s.end());
        s2=s;
        int n=s.size();
        memset(dp,-1,sizeof(dp));
        int length =solve(s1,s2,n-1,n-1);
        return n-length;
    }
};