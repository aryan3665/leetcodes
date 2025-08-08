class Solution {
public:
    bool isUgly(int n) {
        if (n <= 0) return false; // Ugly numbers are positive only
        
        int factors[] = {2, 3, 5};
        for (int f : factors) {
            while (n % f == 0) {
                n /= f;
            }
        }
        
        return n == 1;
    }
};
