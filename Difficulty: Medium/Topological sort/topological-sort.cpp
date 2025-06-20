class Solution {
  public:
  void dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, stack<int>& s) {
     visited[node] = 1;
     for(int j = 0; j < adj[node].size(); j++) {
         if(!visited[adj[node][j]]) {
             dfs(adj[node][j], adj, visited, s);
         }
     }
     s.push(node);
  }

  vector<int> topoSort(int V, vector<vector<int>>& edges) {
      vector<vector<int>> adj(V);
      for(int i = 0; i < edges.size(); i++) {  // FIXED this line
          int u = edges[i][0];
          int v = edges[i][1];
          adj[u].push_back(v);
      }

      vector<bool> visited(V, false);
      stack<int> s;
      for(int i = 0; i < V; i++) {
          if(!visited[i]) {
              dfs(i, adj, visited, s);
          }
      }

      vector<int> ans;
      while(!s.empty()) {
          ans.push_back(s.top());
          s.pop();
      }
      return ans;
  }
};
