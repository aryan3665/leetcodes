class Solution {
public:
    bool dfs(int curr, vector<vector<int>> &adj, int colr, vector<int> &color) {
        color[curr] = colr;

        for (auto &v : adj[curr]) {
            if (color[v] == color[curr]) return false;

            if (color[v] == -1) {
                if (!dfs(v, adj, 1 - colr, color)) return false;
            }
        }

        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Build adjacency list from edge list
        vector<vector<int>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V, -1);
        for (int i = 0; i < V; i++) {
            if (color[i] == -1) {
                if (!dfs(i, adj, 0, color)) return false;
            }
        }

        return true;
    }
};
