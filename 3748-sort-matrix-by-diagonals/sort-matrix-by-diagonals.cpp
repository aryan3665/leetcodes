class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
    unordered_map<int, vector<int>> diagMap;

    // Step 1: Collect elements into diagonals
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            diagMap[i - j].push_back(grid[i][j]);
        }
    }

    // Step 2: Sort each diagonal
    for (auto &p : diagMap) {
        if (p.first >= 0) {
            sort(p.second.begin(), p.second.end(), greater<int>()); // descending
        } else {
            sort(p.second.begin(), p.second.end()); // ascending
        }
    }

    // Step 3: Fill back into grid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            grid[i][j] = diagMap[i - j].front();
            diagMap[i - j].erase(diagMap[i - j].begin()); // pop front
        }
    }

    return grid;
    }
};