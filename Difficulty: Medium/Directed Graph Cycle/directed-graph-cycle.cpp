class Solution {
  public:
  //rohit bhaiya logic

    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>>adj(V);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<int>indegree(V,0);
        for(int i=0;i<V;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        
        queue<int>q;
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        int c=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            c++;
            for(int i=0;i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(!indegree[adj[node][i]]){
                  q.push(adj[node][i]);
              }
            }
        }
        if(c==V)return false;
        return true;
      
      
    }
};