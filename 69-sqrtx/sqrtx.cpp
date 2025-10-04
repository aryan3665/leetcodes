class Solution {
public:
    int mySqrt(int n) {
         if (n == 0 || n == 1) return n;

        int ans = 1;  // initialize safely
        int l = 1;
        int r = n / 2;

        while (l <= r) {
            long long mid = l + (r - l) / 2; // use long long to avoid overflow
            if (mid * mid <= n) {
                ans = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return ans;
    }
};