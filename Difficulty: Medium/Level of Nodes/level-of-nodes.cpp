class Solution {
  public:
    // Function to find the level of node X.
    int nodeLevel(int V, vector<int> adj[], int X) {
        int level = 0;
        vector<bool> visited(V, 0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;

        while (!q.empty()) {
            int n = q.size();  // Number of nodes at current level
            while (n--) {
                int node = q.front(); q.pop();

                if (node == X) return level;

                for (int i = 0; i < adj[node].size(); i++) {
                    if (!visited[adj[node][i]]) {
                        visited[adj[node][i]] = 1;
                        q.push(adj[node][i]);
                    }
                }
            }
            level++;
        }

        return -1;  // Node X not found
    }
};
