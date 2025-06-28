class Solution {
  public:
    bool isPossible(int N, int P, vector<pair<int, int> >& prerequisites) {
        // Code here
        int count=0;
        vector<vector<int>>adj(N);
        for(int i=0;i<P;i++){
                int u=prerequisites[i].first;
                int v=prerequisites[i].second;
                adj[u].push_back(v);
            
        }
        
        vector<int>indegree(N);
        for(int i=0;i<N;i++){
            for(int j=0;j<adj[i].size();j++){
                indegree[adj[i][j]]++;
            }
        }
        queue<int>q;
        for(int i=0;i<N;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[node].size();i++){
                indegree[adj[node][i]]--;
                if(!indegree[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
        }
        
        if(count==N)return true;
        else{
            return false;
        }
    }
};