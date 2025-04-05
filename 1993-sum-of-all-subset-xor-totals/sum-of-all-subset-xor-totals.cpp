class Solution {
public:
void solve(vector<int>&nums,int i,vector<int>&currentsubset,vector<vector<int>>&subsets){
    if(i==nums.size()){
        subsets.push_back(currentsubset);
        return;
    }
    currentsubset.push_back(nums[i]);
    solve(nums,i+1,currentsubset,subsets);
    currentsubset.pop_back();
    solve(nums,i+1,currentsubset,subsets);

}
    int subsetXORSum(vector<int>&nums) {
        vector<vector<int>>subsets;
        vector<int>currsubset;
        solve(nums,0,currsubset,subsets);

        int result=0;
        for(vector<int>&subset:subsets){
            int Xor = 0;
            for(int &num:subset){
                Xor^=num;
            }
            result+=Xor;
        }
        return result ;
    }
};