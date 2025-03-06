class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> ans(2);
        map<int, int> mp;
        int n = grid.size();

        // Count occurrences of each number in the grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                mp[grid[i][j]]++;
            }
        }

        // Find the repeated and missing number
        for (int i = 1; i <= n * n; i++) {  // Iterate from 1 to n*n
            if (mp[i] == 2) {
                ans[0] = i;  // Repeated number
            }
            if (mp[i] == 0) {
                ans[1] = i;  // Missing number
            }
        }

        return ans;
    }
};
