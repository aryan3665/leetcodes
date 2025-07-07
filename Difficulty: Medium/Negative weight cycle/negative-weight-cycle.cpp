class Solution {
  public:
    int isNegativeWeightCycle(int n, vector<vector<int>> edges) {
        // Initialize all distances to 0 (super source trick for disconnected graphs)
        vector<int> dist(n, 0);

        // Relax all edges n - 1 times
        for (int i = 0; i < n - 1; i++) {
            for (auto& edge : edges) {
                int u = edge[0];
                int v = edge[1];
                int w = edge[2];
                if (dist[u] + w < dist[v]) {
                    dist[v] = dist[u] + w;
                }
            }
        }

        // Check for negative weight cycle in 1 more iteration
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            if (dist[u] + w < dist[v]) {
                return 1; // Negative cycle exists
            }
        }

        return 0; // No negative cycle
    }
};
