class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        // Build adjacency list and compute indegree
        for (auto& rel : relations) {
            int u = rel[0] - 1;
            int v = rel[1] - 1;
            adj[u].push_back(v);
            indegree[v]++;
        }

        queue<int> q;
        vector<int> ct(n, 0);  // ct[i]: max time to finish course i

        // Push nodes with 0 indegree and set their initial time
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
                ct[i] = time[i];
            }
        }

        while (!q.empty()) {
            int curr = q.front();
            q.pop();

            for (int next : adj[curr]) {
                indegree[next]--;
                // update time to finish next course
                ct[next] = max(ct[next], ct[curr] + time[next]);
                if (indegree[next] == 0) {
                    q.push(next);
                }
            }
        }

        return *max_element(ct.begin(), ct.end());
    }
};
