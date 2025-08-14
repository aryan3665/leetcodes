class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;
    typedef long long ll;
    vector<vector<pair<ll,ll>>> t;

    pair<ll, ll> solve(int i, int j, vector<vector<int>>& grid) {
        if (i == m - 1 && j == n - 1) {
            return {grid[i][j], grid[i][j]};
        }
        if (t[i][j].first != LLONG_MIN || t[i][j].second != LLONG_MAX)
            return t[i][j];

        ll maxval = LLONG_MIN;
        ll minval = LLONG_MAX;

        // down
        if (i + 1 < m) {
            auto [downmax, downmin] = solve(i + 1, j, grid);
            maxval = max(maxval, max(grid[i][j] * downmax, grid[i][j] * downmin));
            minval = min(minval, min(grid[i][j] * downmax, grid[i][j] * downmin));
        }
        // right
        if (j + 1 < n) {
            auto [rightmax, rightmin] = solve(i, j + 1, grid);
            maxval = max(maxval, max(grid[i][j] * rightmax, grid[i][j] * rightmin));
            minval = min(minval, min(grid[i][j] * rightmax, grid[i][j] * rightmin));
        }

        return t[i][j] = {maxval, minval};
    }

    int maxProductPath(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        t = vector<vector<pair<ll,ll>>>(m, vector<pair<ll,ll>>(n, {LLONG_MIN, LLONG_MAX}));

        auto [maxprod, minprod] = solve(0, 0, grid);
        return maxprod < 0 ? -1 : maxprod % mod;
    }
};
