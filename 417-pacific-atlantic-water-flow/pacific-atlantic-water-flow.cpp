class Solution {
public:
    vector<vector<int>> dir = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    typedef pair<int, int> pp;
    vector<vector<bool>> bfs(vector<vector<int>>& heights, queue<pp>& q) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, 0));
        while(q.size()) {
            auto t = q.front();
            q.pop();
            int r = t.first;
            int c = t.second;
            visited[r][c] = 1;
            for(int i = 0; i < 4; i++) {
                int a = r + dir[i][0];
                int b = c + dir[i][1];
                if(a >= 0 && a < n && b >= 0 && b < m && visited[a][b] != 1 && heights[r][c] <= heights[a][b]) {
                    q.push({a, b});
                    visited[a][b] = 1;
                }
            }
        }
        return visited;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        queue<pp> q1, q2;
        int n = heights.size();
        int m = heights[0].size();
        for(int i = 0; i < n; i++) {
            q1.push({i, 0});
            q2.push({i, m - 1});
        }
        for(int i = 1; i < m; i++) {
            q1.push({0, i});
        }
        for(int i = 0; i < m - 1; i++) {
            q2.push({n - 1, i});
        }
        vector<vector<bool>> v1 = bfs(heights, q1);
        vector<vector<bool>> v2 = bfs(heights, q2);
        vector<vector<int>> ans;
        for(int i = 0 ; i < v1.size(); i++) {
            for(int  j = 0; j < v1[0].size(); j++) {
                if(v1[i][j] && v2[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }
};