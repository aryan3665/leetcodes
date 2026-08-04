class Solution {
  public:
    int sumOfDigits(int n) {
        // code here
     if(n<=0)return 0;
     
     int last=n%10;
     int s=sumOfDigits(n/10);
     return s+last;
    }
};