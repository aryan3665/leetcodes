class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);  // -1 = uncolored, 0 and 1 are two colors

        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue; // already visited

            queue<int> q;
            q.push(start);
            color[start] = 0;

            while (!q.empty()) {
                int node = q.front();
                q.pop();

                for (int nei : graph[node]) {
                    if (color[nei] == -1) {
                        color[nei] = !color[node];
                        q.push(nei);
                    } else if (color[nei] == color[node]) {
                        return false; // conflict found
                    }
                }
            }
        }
        return true;
    }
};
