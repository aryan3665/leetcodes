class Solution {
public:
    void dfs(int city, vector<vector<int>>& isConnected, vector<bool>& visited) {
        visited[city] = true;
        for (int neighbor = 0; neighbor < isConnected.size(); neighbor++) {
            if (isConnected[city][neighbor] == 1 && !visited[neighbor]) {
                dfs(neighbor, isConnected, visited);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int len = isConnected.size();
        vector<bool> visited(len, false);
        int res = 0;
        for (int i = 0; i < len; i++) {
            if (!visited[i]) {
                dfs(i, isConnected, visited);
                res++;
            }
        }
        return res;
    }
};