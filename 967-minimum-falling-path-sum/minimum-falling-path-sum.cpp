#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));

        // Base case: first row is same as matrix
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }

        // Fill dp table
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i][j] + dp[i - 1][j];
                int left_up = (j > 0) ? matrix[i][j] + dp[i - 1][j - 1] : INT_MAX;
                int right_up = (j < n - 1) ? matrix[i][j] + dp[i - 1][j + 1] : INT_MAX;
                dp[i][j] = min(up, min(left_up, right_up));
            }
        }

        // Answer is min in last row
        return *min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};
