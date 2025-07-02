class Solution {
  public:
  bool dfs(int node,int parent,vector<vector<int>>& adj,vector<bool>&visited){
   visited[node]=1;
   for(int j=0;j<adj[node].size();j++){
       if(adj[node][j]==parent)continue;
       if(visited[adj[node][j]]==1)return true;
       if(dfs(adj[node][j],node,adj,visited))return true;
   }
   return false;
      
  }
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
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