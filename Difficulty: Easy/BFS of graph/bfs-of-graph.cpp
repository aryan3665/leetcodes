class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
      queue<int>q;
      q.push(0);
      int v=adj.size();
      vector<bool>visit(v,0);
      vector<int>ans;
      visit[0]=1;
      while(!q.empty()){
          int node=q.front();
          q.pop();
          ans.push_back(node);
          for(int i=0;i<adj[node].size();i++){
              if(!visit[adj[node][i]]){
                  visit[adj[node][i]]=1;
                  q.push(adj[node][i]);
              }
          }
      }
        return ans;
    }
};