// User Function Template
class Solution {
  public:
  typedef pair<int,int>p;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
         vector<vector<pair<int,int>>> adj(V);
        
        // Building adjacency list
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Undirected graph
        }
        priority_queue<p,vector<p>,greater<p>>pq;
        vector<int>result(V,INT_MAX);
        pq.push({0,src});
        result[src]=0;
        while(!pq.empty()){
            int dist=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto&v:adj[node]){
                int adjacentnode=v.first;
                int weight=v.second;
                
                
                if(dist+weight<result[adjacentnode]){
                    result[adjacentnode]=weight+dist;
                    pq.push({weight+dist,adjacentnode});
                }
            }
        }
        
        return result;
        
    }
};