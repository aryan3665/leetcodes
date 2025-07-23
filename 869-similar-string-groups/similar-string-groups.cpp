class Solution {
public:
    bool similar(string& s, string& t) {
        if (s.size() != t.size()) return false;
        vector<int> diff;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] != t[i]) diff.push_back(i);
        }
        if (diff.size() == 0) return true; // same strings
        if (diff.size() != 2) return false;

        return true;
    }

    void dfs(int node, unordered_map<int, vector<int>>& adj, vector<bool>& visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int numSimilarGroups(vector<string>& strs) {
        unordered_map<int, vector<int>> adj;
        int n = strs.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (similar(strs[i], strs[j])) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        vector<bool> visited(n, false);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};
