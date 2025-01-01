class Solution {
public:
    int maxScore(string s) {
        int n = s.size();
        int leftZeros = 0;
        int rightOnes = 0;

        // Count total number of ones in the string
        for (char c : s) {
            if (c == '1') {
                rightOnes++;
            }
        }

        int maxi = 0;

        // Iterate through the string to calculate scores
        for (int i = 0; i < n; i++) {
            if (s[i] == '0') {
                leftZeros++;
            } else {
                rightOnes--;
            }

            // Calculate the score (only if not at the last character)
            if (i < n - 1) {
                maxi = max(maxi, leftZeros + rightOnes);
            }
        }

        return maxi;
    }
};