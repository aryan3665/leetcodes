class Solution {
public:
    int climbStairs(int n) {
        // Base cases
        if (n <= 1) return 1;

        // Two variables to store the last two results
        int n1 = 1; // ways to reach step 0
        int n2 = 1; // ways to reach step 1
        int n3 = 0;

        // Bottom-up DP from step 2 to n
        for (int i = 2; i <= n; i++) {
            n3 = n1 + n2; // current step ways = previous two steps
            n1 = n2;
            n2 = n3;
        }

        return n3;
    }
};
