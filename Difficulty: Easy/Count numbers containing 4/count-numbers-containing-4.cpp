
class Solution {
  public:
  int solve(int n){
       if (n < 4) return 0;
    if (n == 4) return 1;
    
    bool has4 = false;
    int temp = n;
    while (temp) {
        if (temp % 10 == 4) {
            has4 = true;
            break;
        }
        temp /= 10;
    }
    
    return (has4 ? 1 : 0) + solve(n-1);
  }
    int countNumberswith4(int n) {
        // code here
   return solve(n);
    }
};
