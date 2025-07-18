class Solution {
  public:
    vector<vector<int>> ans;

    // Breadth-First Search to collect all nodes in a connected component
    void bfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<int>& r) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            r.push_back(current); // Add current node to the component

            // Visit all unvisited neighbors
            for (auto& v : adj[current]) {
                if (!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
    }

    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V); // Initialize adjacency list

        // Build the graph
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }

        vector<bool> visited(V, false); // Track visited nodes

        // Perform BFS from each unvisited node
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                vector<int> r; // Store one connected component
                bfs(i, adj, visited, r);
                ans.push_back(r);
            }
        }

        return ans;
    }
};
