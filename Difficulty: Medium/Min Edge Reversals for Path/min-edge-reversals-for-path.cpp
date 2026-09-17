class Solution {
  public:
    int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst) {

        unordered_map<int, vector<pair<int, int>>> adj;

        // Build graph
        for (auto &it : edges) {
            int u = it[0];
            int v = it[1];

            // Original direction -> cost 0
            adj[u].push_back({v, 0});

            // Reverse direction -> cost 1
            adj[v].push_back({u, 1});
        }

        vector<int> dist(n + 1, INT_MAX);
        dist[src] = 0;

        deque<int> dq;
        dq.push_front(src);

        while (!dq.empty()) {
            int node = dq.front();
            dq.pop_front();

            for (auto &neg : adj[node]) {
                int padosi = neg.first;
                int cost = neg.second;

                int newDist = dist[node] + cost;

                if (dist[padosi] > newDist) {
                    dist[padosi] = newDist;

                    // 0-cost edge -> process earlier
                    if (cost == 0) {
                        dq.push_front(padosi);
                    }
                    // 1-cost edge -> process later
                    else {
                        dq.push_back(padosi);
                    }
                }
            }
        }

        if (dist[dst] == INT_MAX)
            return -1;

        return dist[dst];
    }
};