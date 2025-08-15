class Solution {
public:
int dp[501][501];
int solve(string &word1, string &word2,int i,int j){
    if(i<0)return j+1;
    if(j<0)return i+1;
    if(dp[i][j]!=-1)return dp[i][j];
    if(word1[i]==word2[j])return solve(word1,word2,i-1,j-1);
    else{
        //if the string char not matching then we are trying out all the  ways to perform the operation and taking out the minimum of all the operations
        int inserted=1+solve(word1,word2,i,j-1);
        int deleted=1+solve(word1,word2,i-1,j);
        int replace=1+solve(word1,word2,i-1,j-1);
        return dp[i][j]=min(inserted,min(deleted,replace));
    }
}
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        int n=word1.size();
        int m=word2.size();
        return solve(word1,word2,n-1,m-1);
    }
};