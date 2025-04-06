class Solution {
public:
set<vector<int>>s;
void solve(vector<int>& arr,int idx,vector<int>&combs,vector<vector<int>> &ans,int target){


if(idx==arr.size()||target<0)return;
if(target==0){
    if(s.find(combs)==s.end()){

    ans.push_back(combs);
    s.insert(combs);
    }
    return;
}

    combs.push_back(arr[idx]);
    solve(arr,idx+1,combs,ans,target-arr[idx]);
    solve(arr,idx,combs,ans,target-arr[idx]);
    combs.pop_back();
    solve(arr,idx+1,combs,ans,target);
}
    vector<vector<int>> combinationSum(vector<int>&arr, int target) {
        vector<int>combs;
        vector<vector<int>>ans;
        
        solve(arr,0,combs,ans,target);
        return ans;
    }
};