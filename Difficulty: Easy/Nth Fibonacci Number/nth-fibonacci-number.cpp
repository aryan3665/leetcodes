// User function Template for C++
class Solution {
  public:
    int nthFibonacci(int n) {
        // code here
        
      if (n == 0) return 0;
        if (n == 1) return 1;

        long long a = 0, b = 1, c;
        for (int i = 2; i <= n; i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
};