// User function Template for C++
class Solution {
  public:
  void topo(int node, vector<pair<int,int>>adj[],stack<int>&s1,vector<bool>&visit){
  visit[node]=1;
  
  for(int j=0;j<adj[node].size();j++){
      if(!visit[adj[node][j].first]){
          topo(adj[node][j].first,adj,s1,visit);
      }
      
  }
  s1.push(node);
      
  }
    vector<int> shortestPath(int N, int M, vector<vector<int>>& edges) {
        // code here
        
        //adjacency list create karte hain pahle
        vector<pair<int,int>>adj[N];
        for(int i=0;i<M;i++){
            int u=edges[i][0];
            int v=edges[i][1];
            int weight=edges[i][2];
            
            adj[u].push_back({v,weight});
        }
        
        //topological sort
        stack<int>s1;
        vector<bool>visit(N,0);
        topo(0,adj,s1,visit);
        vector<int>dist(N,INT_MAX);
        dist[0]=0;
        
        //abb hame stack ko empty karna hai and shortest path calc karenge;
        
        while(!s1.empty()){
            int node=s1.top();
            s1.pop();
            
            //look at padosi
            for(int j=0;j<adj[node].size();j++){
                int padosi=adj[node][j].first;
                int weit=adj[node][j].second;
                dist[padosi]=min(dist[padosi],weit+dist[node]);
            }
        }
        
        for(int i=0;i<N;i++){
            if(dist[i]==INT_MAX){
                dist[i]=-1;
            }
        }
        
        return dist;
        
    }
};
