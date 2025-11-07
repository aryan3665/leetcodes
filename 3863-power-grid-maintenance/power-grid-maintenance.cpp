class Solution {
public:
void dfs(int node, unordered_map<int, vector<int>>&adj,vector<bool>&visited,
int id, vector<int>&compid, unordered_map<int,set<int>>&mp){
    visited[node]=true;
    compid[node]=id;
    mp[id].insert(node);

    for(auto&v:adj[node]){
        if(!visited[v]){
            dfs(v,adj,visited,id,compid,mp);
        }
    }

}
    vector<int> processQueries(int c, vector<vector<int>>& connections,
                               vector<vector<int>>& queries) {
        unordered_map<int, vector<int>> adj;
        //adjacency matrix banayenge
        for (int i = 0; i < connections.size(); i++) {
            int u = connections[i][0];
            int v = connections[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //dfs lagake precomputings karna hai 
        vector<bool>visited(c+1,0);
        vector<int>compid(c+1);
        unordered_map<int,set<int>>mp;
        for(int i=1;i<=c;i++){
            if(!visited[i]){
                int id=i;
                dfs(i,adj,visited,id,compid,mp);
            }
        }

        vector<int>result;
        for(auto&query:queries){
            int type=query[0];//1/2
            int x=query[1];
            if(type==1){
                int ids=compid[x];
                if(mp[ids].count(x)){
                    result.push_back(x);
                }
                else if(!mp[ids].empty()){
                    result.push_back(*mp[ids].begin());
                }
                else{
                    result.push_back(-1);
                }
            }
            else{
               int ids=compid[x];
               mp[ids].erase(x);
            }
        }
        return result;
    }
};