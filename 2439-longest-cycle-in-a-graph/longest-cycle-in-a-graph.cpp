class Solution {
public:
    int result = -1;

    void dfs(int u, vector<int>& edges, vector<bool>& visited,
             vector<int>& count, vector<bool>& inrecurr) {
        if (u == -1) return;

        visited[u] = true;
        inrecurr[u] = true;
        int v = edges[u];
        if (v != -1) {
            if (!visited[v]) {
                count[v] = count[u] + 1;
                dfs(v, edges, visited, count, inrecurr);
            } else if (inrecurr[v]) {
                result = max(result, count[u] - count[v] + 1);
            }
        }
        inrecurr[u] = false;
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<bool> inrecurr(n, false);
        vector<bool> visited(n, false);
        vector<int> count(n, 1);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                count[i] = 1;
                dfs(i, edges, visited, count, inrecurr);
            }
        }
        return result;
    }
};
