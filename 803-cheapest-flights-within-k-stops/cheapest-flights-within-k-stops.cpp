

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;

        // Build the adjacency list
        for (auto& v : flights) {
            int u = v[0];
            int v1 = v[1];
            int wt = v[2];
            adj[u].push_back({v1, wt});
        }

        // Distance vector initialized with INT_MAX
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        // Queue stores {node, cost}
        queue<pair<int, int>> q;
        q.push({src, 0});

        int steps = 0;

        while (!q.empty() && steps <= k) {
            int size = q.size();


            for (int i = 0; i < size; ++i) {
                int node = q.front().first;
                int cost = q.front().second;
                q.pop();

                for (auto& neighbor : adj[node]) {
                    int nextNode = neighbor.first;
                    int price = neighbor.second;

                    if (cost + price < dist[nextNode]) {
                        dist[nextNode] = cost + price;
                        q.push({nextNode, dist[nextNode]});
                    }
                }
            }

           
            steps++;
        }

        return dist[dst] == INT_MAX ? -1 : dist[dst];
    }
};
