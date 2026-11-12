class Solution {
    public void reverseString(char[] s) {
        f(s, 0, s.length - 1); // Removed parentheses from length
    }

    static void f(char[] s, int i, int j) {
        // Base case: stop when pointers meet or cross
        if (i >= j) return;
        
        // Swap characters at indices i and j
        char t = s[i];
        s[i] = s[j];
        s[j] = t;
        
        
        f(s, i + 1, j - 1);
    }
}
