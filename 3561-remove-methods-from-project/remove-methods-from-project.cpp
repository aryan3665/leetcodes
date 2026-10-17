// class Solution {
// public:

// void dfs(int start,vector<bool>&visited,unordered_map<int,vector<int>>&adj){
//     visited[start]=1;
//     for(int &it:adj[start]){
//         if(!visited[it]){
//             dfs(it,visited,adj);
//         }
//     }
// }
//     vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        
//   //make an adj 
//   unorderd_map<int,vector<int>>adj;
//   for(int&it:invocations){
//     int u=it[0];
//     int v=it[1];
//     adj[u].push_back(v);
//   }
//         // with help of dfs hamm find karlenge ki kaun kaun se suspicious node hain 
//         vector<bool>visited(n,0);

//         // abb k se dfs mar denge
//         dfs(k,visited,adj);

//         // abb apne pass sare suspisous node aa gaye
//         set<int>st;
//         for(int i=0;i<n;i++){
//             if(visited[i]==1){
//                 st.insert(i);
//             }
//         }


//         // now abb hame ye check karna hai ki kahi ye jo nodes hamre set me hai unme se kisi par bhi kisi unvisted node se edge to nhi hai agar hui to hamm kuch delete nhi karsakte we should return an array from 0 to n aur agar ek bhi nhi mila to visted array ke sabhi unvisted walon ko return kardenge 

//     }
// };



class Solution {
public:
    void dfs(int start, vector<bool>& visited,
             unordered_map<int, vector<int>>& adj) {
        visited[start] = 1;

        for (int &it : adj[start]) {
            if (!visited[it]) {
                dfs(it, visited, adj);
            }
        }
    }

    vector<int> remainingMethods(
        int n, int k, vector<vector<int>>& invocations) {

        unordered_map<int, vector<int>> adj;

        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        vector<bool> visited(n, 0);
        dfs(k, visited, adj);

        // Check if any non-suspicious method
        // invokes a suspicious method
        for (auto &it : invocations) {
            int u = it[0];
            int v = it[1];

            if (!visited[u] && visited[v]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        // Return all non-suspicious methods
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};
