class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> flat;
        for (auto& row : grid) {
            for (int val : row) {
                flat.push_back(val);
            }
        }

        int rem = flat[0] % x;
        for (int val : flat) {
            if (val % x != rem) return -1;
        }

        sort(flat.begin(), flat.end());
        int median = flat[flat.size() / 2];

        int operations = 0;
        for (int val : flat) {
            operations += abs(val - median) / x;
        }

        return operations;
    }
};
