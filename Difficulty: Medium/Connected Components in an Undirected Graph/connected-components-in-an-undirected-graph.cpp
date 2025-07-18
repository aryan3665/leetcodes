
class Solution {
  public:
  vector<vector<int>>ans;
  void dfs(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&r){
      visited[node]=1;
      r.push_back(node);
      
      for(auto&v:adj[node]){
          if(!visited[v]){
              dfs(v,adj,visited,r);
          }
      
          
      }
      
   
  }
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
       
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                 vector<int>r;
                dfs(i,adj,visited,r);
                   ans.push_back(r);
                   //empty r
               
            }
        }
        
        return ans;
    }
};
