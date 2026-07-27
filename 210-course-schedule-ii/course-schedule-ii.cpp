class Solution {
public:

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int>indegree(numCourses,0);
        for (auto& p : prerequisites) {
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

       queue<int>q;
       for(int i=0;i<indegree.size();i++){
        if(indegree[i]==0){
            q.push(i);
        }
       }

       

        vector<int> result;
        while(!q.empty()){
            int frnt=q.front();
            q.pop();
            result.push_back(frnt);
            for(auto&it:adj[frnt]){
                indegree[it]--;
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }

        if(result.size()!=numCourses)return {};
        return result;
       
    }
};
