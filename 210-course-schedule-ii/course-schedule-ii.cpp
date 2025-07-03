class Solution {
public:
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, vector<bool>& recStack, stack<int>& s) {
        visited[node] = true;
        recStack[node] = true;

        for (auto& neighbour : adj[node]) {
            if (!visited[neighbour]) {
                if (dfs(neighbour, adj, visited, recStack, s)) {
                    return true;  // Cycle found
                }
            } else if (recStack[neighbour]) {
                return true;  // Cycle detected
            }
        }

        recStack[node] = false;
        s.push(node);
        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> recStack(numCourses, false);
        stack<int> s;

        for (int i = 0; i < numCourses; ++i) {
            if (!visited[i]) {
                if (dfs(i, adj, visited, recStack, s)) {
                    return {};  // cycle detected
                }
            }
        }

        vector<int> result;
        while (!s.empty()) {
            result.push_back(s.top());
            s.pop();
        }

        return result;
    }
};
