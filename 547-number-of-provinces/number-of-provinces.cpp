class Solution {
public:
void dfs(int node,  unordered_map<int, vector<int>> &adj,vector<bool>&visited){
    visited[node]=true;
    for(int&v:adj[node]){
        if(!visited[v]){
            dfs(v,adj,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, 0);
        unordered_map<int, vector<int>> adj;
int count=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                dfs(i, adj,visited);
                count++;
            }
        }


        return count;
    }
};