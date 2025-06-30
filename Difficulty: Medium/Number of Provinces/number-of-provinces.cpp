// User function Template for C++

class Solution {
  public:
  void bfs(int node,vector<vector<int>>&adjc,vector<bool>&visited){
      visited[node]=1;
      queue<int>q;
      q.push(node);
      while(!q.empty()){
          
      int node=q.front();
      q.pop();
      for(int i=0;i<adjc[node].size();i++){
          if(!visited[adjc[node][i]]){
           visited[adjc[node][i]]=true;
           q.push(adjc[node][i]);
          }
      
      }
      }
  }
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int c=0;
        vector<vector<int>>adjc(V);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[0].size();j++){
                if(adj[i][j]==1){
                    adjc[i].push_back(j);
                    adjc[j].push_back(i);
                }
            }
        }
        
        vector<bool>visited(V,0);
        for(int i=0;i<V;i++){
            if(!visited[i]){
                bfs(i,adjc,visited);
                c++;
            }
        }
        
        return c;
        
    }
};