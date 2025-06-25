class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses); 

        // Build adjacency list
        for (const auto& pre : prerequisites) {
            int u = pre[1]; // prerequisite course
            int v = pre[0]; // course that depends on u
            adj[u].push_back(v);
        }

        vector<int> indegree(numCourses, 0);
        
        for (int i = 0; i < numCourses; ++i) {
            for (int j : adj[i]) {
                indegree[j]++;
            }
        }

        queue<int> q;

        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) q.push(i);
        }

        int count = 0;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            count++;

            for (int neighbor : adj[node]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }

        // If all courses are processed, return true
        return count == numCourses;
    }
};
