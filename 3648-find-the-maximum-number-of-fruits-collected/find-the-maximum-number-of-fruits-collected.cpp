class Solution {
public:
    int maxCollectedFruits(vector<vector<int>>& fruits) {
        const int n = fruits.size();
        int f0, f1, f2;

        for (int i = 1; i < n; i++) {
            // Child A (diagonal)
            fruits[i][i] += fruits[i - 1][i - 1];

            for (int j = i + 1; j < n; j++) {
                if (i + j < n - 1) continue;

                // Child B possible previous positions
                f0 = (j > 0 && i + j > n) ? fruits[i - 1][j - 1] : 0; // down-left (i-1, j-1)
                f1 = (i + j == n - 1) ? 0 : fruits[i - 1][j]; // down (i-1, j)
                f2 = (j < n - 1) ? fruits[i - 1][j + 1] : 0; // down-right (i-1, j+1)
                fruits[i][j] += max(f0, max(f1, f2));

                // Child C possible previous positions
                f0 = (j > 0 && i + j > n) ? fruits[j - 1][i - 1] : 0; // left-up (j-1, i-1)
                f1 = (i + j == n - 1) ? 0 : fruits[j][i - 1]; // left (j, i-1)
                f2 = (j < n - 1) ? fruits[j + 1][i - 1] : 0; // left-down (j+1, i-1)
                fruits[j][i] += max(f0, max(f1, f2));
            }
        }

        return fruits[n - 1][n - 2] + fruits[n - 2][n - 1] + fruits[n - 1][n - 1];
    }
};