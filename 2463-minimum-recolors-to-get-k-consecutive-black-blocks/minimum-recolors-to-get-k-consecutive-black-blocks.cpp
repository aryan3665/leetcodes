class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int op = INT_MAX;  // Initialize to a large value
        int c = 0;

        for (int i = 0; i <= n - k; i++) {  // Ensure we check all k-length substrings
            c = 0;  // Reset count for each new window

            for (int j = i; j-i+1<= k; j++) { 
                if (blocks[j] == 'W') {
                    c++;  // Count 'W' blocks in the window
                }
            }

            op = min(op, c);  // Update the minimum number of recolors
        }

        return op;
    }
};
