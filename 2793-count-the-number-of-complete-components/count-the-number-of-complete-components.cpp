class Solution {
public:
void dfs(int node,vector<vector<int>> &adj, vector<bool> &visited,int &v,int &e){
    visited[node]=1;
    v++;
    e+=adj[node].size();
    for(auto&neig:adj[node]){
        if(!visited[neig]){
            dfs(neig,adj,visited,v,e);
        }
    }
}

bool iscomplete(int v,int e){
    int k=(v*(v-1))/2;
    return k==e;
}
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        // dekho bhai complete graph usko bolte hain jisme v*(v-1)/2=edges hota
        // hai and isi condition ko dekhenge hamm log yaha pe ok dfs ya bfs se
        // travesal kartye hue hamm vertex and edges count karlenge and check kr
        // lenge ki complete component hai ya nhi hi
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<bool> visited(n, 0);
        int count = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int v = 0;
                int e = 0;
                dfs(i, adj, visited, v, e);
                if (iscomplete(v, e/2)) {
                    count++;
                }
            }
        }
        return count;
    }
};