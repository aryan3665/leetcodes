
class Solution {
  public:
    // Function to count the number of ways in which frog can reach the top.
    int countWays(int n) {

        // your code here
         if (n < 0) return 0;
        if(n==0)return 1;
        return countWays(n-1)+countWays(n-2)+countWays(n-3);
    }
};
