class Solution {
public:
    bool bip(vector<vector<int>>& adj) {
        int n = adj.size();
        vector<int> color(n, -1);
        for (int start = 0; start < n; start++) {
            if (color[start] != -1)
                continue; // already visited)
            queue<int> q;
            q.push(start);
            color[start] = 0; // assign first color

            while (!q.empty()) {
                int u = q.front();
                q.pop();

                for (int v : adj[u]) {
                    if (color[v] == -1) {
                        // Assign opposite color
                        color[v] = color[u] ^ 1;
                        q.push(v);
                    } else if (color[v] == color[u]) {
                        // Conflict -> not bipartite
                        return false;
                    }
                }
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>> adj(n); // 0-indexed graph
        for (auto& d : dislikes) {
            int u = d[0] - 1; // convert to 0-index
            int v = d[1] - 1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return bip(adj);
    }
};