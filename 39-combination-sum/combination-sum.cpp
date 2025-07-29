class Solution {
public:
void solve(int i,vector<int>& candidates,int target,vector<int>&temp, vector<vector<int>>&ans){

  if(target==0){
    ans.push_back(temp);
    return;
  }
  if(i==candidates.size()||target<0){
    return;
  }


    //not take

    solve(i+1,candidates,target,temp,ans);
    //taken
    temp.push_back(candidates[i]);
    solve(i,candidates,target-=candidates[i],temp,ans);
    target+=candidates[i];
    temp.pop_back();
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,target,temp,ans);
        return ans;
    }
};