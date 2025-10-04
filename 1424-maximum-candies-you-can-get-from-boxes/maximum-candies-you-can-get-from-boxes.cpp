class Solution {
public:

int dfs(int box,vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes,unordered_set<int>&visited,unordered_set<int>&found){
    if (visited.count(box)) {
            return 0; // already visited
        }

    if(status[box]==0){
        //agar box closed hai to usko found me daldo taki bad me process kar sake agar key mil jaye and return 0;
        found.insert(box);
        return 0;
    }

    visited.insert(box);
    int candis=candies[box];//abb jitna candie mile usko le lo
    for(auto&it:containedBoxes[box]){
        candis+=dfs(it,status,candies,keys,containedBoxes,visited,found);
    }

    for(auto&it:keys[box]){
        status[it]=1;
        if(found.count(it)){
            candis+=dfs(it,status,candies,keys,containedBoxes,visited,found);
        }
    }
    return candis;
}
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int total=0;
        unordered_set<int>visited;
        unordered_set<int>found;
        for(auto &box:initialBoxes){
            total+=dfs(box,status,candies,keys,containedBoxes,visited,found);
        }

        return total;
    }
};