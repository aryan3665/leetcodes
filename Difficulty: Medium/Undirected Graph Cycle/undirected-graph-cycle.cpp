class Solution {
public:
    bool dfs(int start,int parent, vector<vector<int>>& adj, vector<bool>& visited) {
       visited[start]=1;
       for(auto&v:adj[start]){
           if(v==parent)continue;
           if(visited[v]==true)return true;
           if(dfs(v,start,adj,visited)==true)return true;
       }
       return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i,-1, adj, visited)) return true;
            }
        }
        return false;
    }
};
