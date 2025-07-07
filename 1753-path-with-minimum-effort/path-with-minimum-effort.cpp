class Solution {
public:
    typedef pair<int, pair<int, int>> p;
    vector<vector<int>> d = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        priority_queue<p, vector<p>, greater<p>> pq;
        pq.push({0, {0, 0}});
        result[0][0] = 0;

        auto issafe = [&](int x, int y) {
            return x >= 0 && y >= 0 && x < m && y < n;
        };

        while (!pq.empty()) {
            int diff = pq.top().first;
            auto coord = pq.top().second;
            pq.pop();
            int x = coord.first;
            int y = coord.second;

           

            for (auto& dir : d) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                if (issafe(x_, y_)) {
                    int absdiff = abs(heights[x][y] - heights[x_][y_]);
                    int maxdiff = max(diff, absdiff);

                    if (result[x_][y_] > maxdiff) {
                        result[x_][y_] = maxdiff;
                        pq.push({maxdiff, {x_, y_}});
                    }
                }
            }
        }

        return result[m - 1][n - 1];
    }
};
