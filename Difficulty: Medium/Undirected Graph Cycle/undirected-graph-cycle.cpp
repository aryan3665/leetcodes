class Solution {
  public:
  bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>visited){
      visited[node]=true;
      
      for(int i=0;i<adj[node].size();i++){
          if(adj[node][i]==parent)continue;
          if(visited[adj[node][i]]==1)return true;
          if(dfs(adj[node][i],node,adj,visited))return true;
      }
      return false;
  }
 
    bool isCycle(int V, vector<vector<int>>& edges) {
        
         vector<vector<int>> adj(V);
        // Build the adjacency list
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); // Undirected graph
        }
        
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
               if( dfs(i,-1,adj,visited))return true;
            }
        }
        return false;
    }
};