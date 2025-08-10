#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp = matrix; // copy original costs

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int left_up = (j > 0) ? dp[i-1][j-1] : INT_MAX;
                int right_up = (j < n-1) ? dp[i-1][j+1] : INT_MAX;
                dp[i][j] += min(up, min(left_up, right_up));
            }
        }

        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};
