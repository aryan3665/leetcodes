// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src]=0;
        for(int i=1;i<=V-1;i++){
            for(auto&edge:edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                if(dist[u]!=1e8){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                }
                }
            }
        }
        //agar v-1 se 1 jada bar relax karne ki kosis ki and relax ho gaya to pakka usme negative cycle hoga hi 
         for(auto&edge:edges){
                int u=edge[0];
                int v=edge[1];
                int wt=edge[2];
                     if(dist[u]!=1e8){
                if(dist[u]+wt<dist[v]){
                    dist[v]=dist[u]+wt;
                    return {-1};
                }
                     }
            }
            
            return dist;
    }
};
