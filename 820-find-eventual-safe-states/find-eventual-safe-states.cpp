class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);      // reversed graph
        vector<int> indegree(n, 0);

        // Build reverse graph and indegree
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < graph[i].size(); j++) {
                adj[graph[i][j]].push_back(i);   // ✅ reverse edge
                indegree[i]++;                   // count indegree
            }
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);   // terminal nodes
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            ans.push_back(node);   // ✅ push_back

            for (int neigh : adj[node]) {
                indegree[neigh]--;
                if (indegree[neigh] == 0) {
                    q.push(neigh);
                }
            }
        }

        sort(ans.begin(), ans.end());   // answer in sorted order
        return ans;
    }
};
