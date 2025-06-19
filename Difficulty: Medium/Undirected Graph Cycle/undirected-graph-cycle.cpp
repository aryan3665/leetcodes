class Solution {
public:
    bool detect(int node, int parent, vector<vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (visited[neighbor]) return true;
            if (detect(neighbor, node, adj, visited)) return true;
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }

        vector<bool> visited(V, false);
        // Check each component
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (detect(i, -1, adj, visited)) return true;
            }
        }
        return false;
    }
};
