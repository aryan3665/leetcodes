class Solution {
  public:
  void dfs(int node,vector<bool>&visited,vector<vector<int>>& adj,vector<int>&ans){
      visited[node]=true;
      ans.push_back(node);
      
      for(int v=0;v<adj[node].size();v++){
          if(!visited[adj[node][v]]){
              dfs(adj[node][v],visited,adj,ans);
          }
      }
  }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<bool>visited(n,0);
        vector<int>ans;
        
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,visited,adj,ans);
            }
        }
        
        
        return ans;
    }
};