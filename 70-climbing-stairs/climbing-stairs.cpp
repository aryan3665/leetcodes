class Solution {
public:
//    int dp[46];
// int f(int n){
//     if(n<=1)return 1;
//     if(dp[n]!=-1)return dp[n];

//     int one=f(n-1);
//     int two=f(n-2);
//     return dp[n]=one+two;
// }
    int climbStairs(int n) {
int dp[46];
dp[1]=1;
dp[2]=2;
for(int i=3;i<=n;i++){
 int one=dp[i-1];
    int two=dp[i-2];
   dp[i]=one+two;
}

return dp[n];
     
    }
};