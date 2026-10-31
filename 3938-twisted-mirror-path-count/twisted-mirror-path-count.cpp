
class Solution {
public:
    const int MOD = 1e9 + 7;
    int m, n;
    vector<vector<int>> grid;
    vector<vector<vector<int>>> dp;

    // prev = -1 : starting cell
    // prev =  0 : entered from Left (moving Right)
    // prev =  1 : entered from Top  (moving Down)

    int solve(int i, int j, int prev) {

        // Out of bounds
        if (i >= m || j >= n)
            return 0;

        // Destination reached
        if (i == m - 1 && j == n - 1)
            return 1;

        if (dp[i][j][prev + 1] != -1)
            return dp[i][j][prev + 1];

        long long ans = 0;

        // Starting cell: no reflection on entry
        if (prev == -1) {
            ans = (solve(i, j + 1, 0) +
                   solve(i + 1, j, 1)) % MOD;
        }

        // Empty cell: choose Right or Down
        else if (grid[i][j] == 0) {
            ans = (solve(i, j + 1, 0) +
                   solve(i + 1, j, 1)) % MOD;
        }

        // Mirror entered while moving Right
        else if (prev == 0) {
            ans = solve(i + 1, j, 1);
        }

        // Mirror entered while moving Down
        else {
            ans = solve(i, j + 1, 0);
        }

        return dp[i][j][prev + 1] = ans;
    }

    int uniquePaths(vector<vector<int>>& matrix) {
        grid = matrix;
        m = grid.size();
        n = grid[0].size();

        dp.assign(m, vector<vector<int>>(n, vector<int>(3, -1)));

        return solve(0, 0, -1);
    }
};