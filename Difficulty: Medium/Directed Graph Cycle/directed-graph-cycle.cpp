class Solution {
  public:
  //rohit bhaiya logic
  bool dfsdetect(int node,vector<vector<int>>&adj,vector<bool>&visited,vector<bool>&path){
   
       visited[node]=1;
       path[node]=1;
   
   for(int j=0;j<adj[node].size();j++){
       
       //if node is alredy present in path to cycle present hai
       if(path[adj[node][j]]==1)return 1;
       
       else{
       //if neighbour alredy visited hai to ignore karo
       if(visited[adj[node][j]])continue;
       
       if(dfsdetect(adj[node][j],adj,visited,path))return 1;
       }
   }
   
   path[node]=0;
   return 0;
  }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        vector<bool>path(V,0);
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                if(dfsdetect(i,adj,visited,path))return 1;
            }
        }
        return 0;
    }
};