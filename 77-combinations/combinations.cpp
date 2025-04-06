class Solution {
public:
    void solve(int start, int n, int k, vector<int>& combs, vector<vector<int>>& ans) {
        if (k == 0) {
            ans.push_back(combs);
            return;
        }
        for (int i = start; i <= n; ++i) {
            combs.push_back(i);
            solve(i + 1, n, k - 1, combs, ans);
            combs.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combs;
        solve(1, n, k, combs, ans);
        return ans;
    }
};
