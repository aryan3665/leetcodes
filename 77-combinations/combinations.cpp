class Solution {
public:
    void solve(const vector<int>& arr, int idx, vector<int>& combs,
               vector<vector<int>>& ans, int k) {
        if (k == 0) {
            ans.push_back(combs);
            return;
        }
        if (idx == arr.size()) {
            return;
        }

        // Include current element
        combs.push_back(arr[idx]);
        solve(arr, idx + 1, combs, ans, k - 1);

        // Exclude current element
        combs.pop_back();
        solve(arr, idx + 1, combs, ans, k);
    }

    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> combs;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i) {
            arr[i] = i + 1;
        }

        solve(arr, 0, combs, ans, k);
        return ans;
    }
};
