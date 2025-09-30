class Solution {
  public:
    // Function to perform BFS traversal from a given node
    void bft(int node, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &bfst) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int n = q.front();
            q.pop();
            bfst.push_back(n);

            for (int i = 0; i < adj[n].size(); i++) {
                int neighbor = adj[n][i];
                if (!visited[neighbor]) {
                    visited[neighbor] = true;   // ✅ Mark here itself
                    q.push(neighbor);
                }
            }
        }
    }
    
    // Main BFS function for disconnected graph
    vector<int> bfs(vector<vector<int>> &adj) {
        vector<int> bfst;  
        vector<bool> visited(adj.size(), false);
        
        for (int i = 0; i < visited.size(); i++) {
            if (!visited[i]) {
                bft(i, adj, visited, bfst);
            }
        }
        return bfst;
    }
};
