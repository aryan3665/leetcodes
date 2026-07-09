class Solution {
public:

void dfs(int node,  vector<int>adj[],vector<bool>&visited){
    visited[node]=true;
    for(int&v:adj[node]){
        if(!visited[v]){
            dfs(v,adj,visited);
        }
    }
}
    int findCircleNum(vector<vector<int>>& P) {
        int n=P.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<P[0].size();j++){
                if(P[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count=0;
        vector<bool>visited(n,0);
        for(int i=0;i<n;i++){
            if(!visited[i]){
                dfs(i,adj,visited);
                count++;
            }
        }
        return count;
    }
};