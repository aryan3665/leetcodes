class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        queue<pair<int,int>>q;
        q.push({src,0});
        vector<bool>visited(adj.size(),0);
        vector<int>dist(adj.size(),-1);
        dist[src]=0;
        visited[src]=1;
        // int level=1;
        while(!q.empty()){
            int n=q.size();
            while(n--){
                 int node=q.front().first;
                 int d=q.front().second;
                 q.pop();
                 for(int j=0;j<adj[node].size();j++){
                     if(!visited[adj[node][j]]){
                         dist[adj[node][j]]=d+1;
                         visited[adj[node][j]]=1;
                         q.push({adj[node][j],dist[adj[node][j]]});
                     }
                 }
            }
            
           
        }
        return dist;
    }
};