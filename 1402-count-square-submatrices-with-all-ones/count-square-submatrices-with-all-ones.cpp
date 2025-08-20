class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int res = 0;
        vector<int> prev(n, 0), curr(n, 0);
        for (int i = 0; i < n; i++) {
            if (matrix[0][i] == 1) {
                res += 1;
                prev[i] = 1;
            }
        }

        for (int i = 1; i < m; i++) {
            curr[0] = (matrix[i][0] == 1);
            res += curr[0];
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] == 1) {
                    curr[j] = 1 + min(prev[j - 1], min(prev[j], curr[j - 1]));
                } else
                    curr[j] = 0;
                res += curr[j];
            }
            prev = curr;
        }
        return res;
    }
};