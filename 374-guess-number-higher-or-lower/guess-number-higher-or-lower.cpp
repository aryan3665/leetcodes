class Solution {
public:
    int guessNumber(int n) {
        int start = 1, end = n;
        
        while (start <= end) {  
            int g = start + (end - start) / 2;  
            
            int res = guess(g);
            if (res == 0) {
                return g;  
            } else if (res == -1) {
                end = g - 1;  
            } else {
                start = g + 1; 
            }
        }
        
        return -1; // Just a safety return, code should never reach here
    }
};
