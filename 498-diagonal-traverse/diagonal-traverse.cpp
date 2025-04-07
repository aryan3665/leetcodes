class Solution {
public:
    // i+j /^
    // i-j \>
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> mp;
        vector<int> result;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        bool flip = true;

        for (auto& i : mp) {
            if (flip) {
                reverse(i.second.begin(), i.second.end());
            }
            for (int& num : i.second) {
                result.push_back(num);
            }
            flip = !flip;
        }
        return result;
    }
};