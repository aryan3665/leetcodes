class Solution {
public:
    // Recursive function returning 0-based winner
    int winner(int n, int k) {
        if (n == 1) return 0;
        return (winner(n - 1, k) + k) % n;
    }

    int findTheWinner(int n, int k) {
        return winner(n, k) + 1; // Convert to 1-based index
    }
};
