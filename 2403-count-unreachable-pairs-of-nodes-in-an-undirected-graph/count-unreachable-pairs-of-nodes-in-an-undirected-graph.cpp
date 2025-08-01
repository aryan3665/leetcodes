class Solution {
public:
    void dfs(int u, unordered_map<int, vector<int>>& adj, vector<bool>& visited,
             long long& size) {
        visited[u] = true;
        size++;
        for (auto& v : adj[u]) {
                 if (!visited[v]) {
                     dfs(v, adj, visited, size);
                 }
             }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto& vec : edges) {
            int u = vec[0];
            int v = vec[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, 0);
        long long remaining = n;
        long long result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                long long size = 0;
                dfs(i, adj, visited, size);
                result += size * (remaining - size);
                remaining -= size;
            }
        }
        return result;
    }
};