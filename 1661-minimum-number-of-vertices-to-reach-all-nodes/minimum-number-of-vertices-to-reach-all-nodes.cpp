class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // approch is to give ans of the node that have indegree 0;

        vector<int> indeg(n, 0);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            indeg[v]++;
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (indeg[i] == 0) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};