class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& ans) {
        visited[node] = true;
        ans.push_back(node);
        for (int i = 0; i < adj[node].size(); i++) {
            if (!visited[adj[node][i]]) {
                dfs(adj[node][i], adj, visited, ans);
            }
        }
    }

    vector<int> dfs(vector<vector<int>>& adj) {
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                dfs(i, adj, visited, ans);
            }
        }
        return ans;
    }
};
