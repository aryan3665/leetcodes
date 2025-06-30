class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> indegree(n + 1, 0); // Number of people trusting them
        vector<int> out(n + 1, 0);      // Number of people they trust

        for (int i = 0; i < trust.size(); i++) {
            int u = trust[i][0]; // truster
            int v = trust[i][1]; // trusted
            out[u]++;
            indegree[v]++;
        }

        for (int i = 1; i <= n; i++) {
            if (indegree[i] == n - 1 && out[i] == 0) {
                return i; // found the judge
            }
        }

        return -1; // no judge
    }
};
