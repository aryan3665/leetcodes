class Solution {
public:
   vector<vector<int>>ans;
   void sol(int i,vector<int>& candidates, int target,vector<int>&temp){
    if(target==0){
        ans.push_back(temp);
        return ;
    }
    if(i>=candidates.size()||target<0)return;
    //not take the candidate
    sol(i+1,candidates,target,temp);
    //take;
    temp.push_back(candidates[i]);
    sol(i,candidates,target-candidates[i],temp);
    temp.pop_back();
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        sol(0,candidates,target,temp);
        return ans;
     
    }
};