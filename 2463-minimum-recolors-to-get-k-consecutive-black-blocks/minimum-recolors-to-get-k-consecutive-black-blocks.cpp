class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size();
        int op = INT_MAX; 
        int c = 0;

        
        for (int i = 0; i < k; i++) {
            if (blocks[i] == 'W') {
                c++;
            }
        }
        op = c;

        // Sliding Window: Move the window one step at a time
        for (int i = k; i < n; i++) {
            if (blocks[i] == 'W') c++; 
            if (blocks[i - k] == 'W') c--;

            op = min(op, c); 
        }

        return op;
    }
};
