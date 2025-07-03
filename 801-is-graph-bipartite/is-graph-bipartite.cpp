class Solution {
public:
    bool dfs(int node, vector<vector<int>>& graph, vector<int>& color,
             int currcolor) {
        color[node] = currcolor;
        for (int& v : graph[node]) {
            if (color[v] == color[node])
                return false;
            if (color[v] == -1) {
                int colorv = 1 - color[node];

                if (dfs(v, graph, color, colorv) == false)
                    return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for (int i = 0; i < graph.size(); i++) {
            if (color[i] == -1) {
                if (dfs(i, graph, color, 1) == false)
                    return false;
            }
        }
        return true;
    }
};