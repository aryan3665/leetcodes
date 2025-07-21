
class Solution {
public:
    // Dijkstra function to compute shortest paths from a given node
    void dijkstra(int start, vector<int>& dist, const vector<vector<int>>& adj) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        dist[start] = 0;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currDist, u] = pq.top();
            pq.pop();

            if (currDist > dist[u]) continue;

            for (int v : adj[u]) {
                if (dist[v] > currDist + 1) {
                    dist[v] = currDist + 1;
                    pq.push({dist[v], v});
                }
            }
        }
    }

    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<vector<int>> adj(n);

        // Create adjacency list
        for (int i = 0; i < n; ++i) {
            if (edges[i] != -1) {
                adj[i].push_back(edges[i]);
            }
        }

        vector<int> dist1(n, INT_MAX), dist2(n, INT_MAX);

        dijkstra(node1, dist1, adj);
        dijkstra(node2, dist2, adj);

        int minDist = INT_MAX;
        int result = -1;

        for (int i = 0; i < n; ++i) {
            if (dist1[i] != INT_MAX && dist2[i] != INT_MAX) {
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDist) {
                    minDist = maxDist;
                    result = i;
                }
            }
        }

        return result;
    }
};
