class Solution {
public:


    int fib(int n) {
    vector<int>dp(n+1,-1);
    if(n<=1)return n;
   int n1=0;
   int n2=1;
   int n3;
   for(int i=1;i<n;i++){
   n3=n2+n1;
    n1=n2;
    n2=n3;
   }
   
  return n3;
    }
};