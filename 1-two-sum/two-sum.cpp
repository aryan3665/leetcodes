class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            ans.push_back(i);
            for(int j=i+1;j<n;j++){
                if(nums[j]==target-nums[i]){
                    ans.push_back(j);
                    break;
                }
            }
            if(ans.size()!=2){
                ans.pop_back();
            }
        }
        return ans;
    }
};