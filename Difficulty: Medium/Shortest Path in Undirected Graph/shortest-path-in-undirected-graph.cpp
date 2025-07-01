class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        vector<int> ans(adj.size(),-1);
        vector<bool> visit(adj.size(),false);
        
        queue<int>q;
        q.push(src);
        ans[src] = 0;
        visit[src] = true;
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                int front = q.front();
                q.pop();
                for(int j =0;j<adj[front].size();j++){
                    if(!visit[adj[front][j]]){
                        ans[adj[front][j]] = dist;
                        visit[adj[front][j]] = true;
                        q.push(adj[front][j]);
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};