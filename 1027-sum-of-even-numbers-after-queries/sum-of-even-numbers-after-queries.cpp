class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>ans;
        int s=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                s+=nums[i];
            }
        }
        for(int i=0;i<queries.size();i++){
            int val=queries[i][0];
            int idx=queries[i][1];
            if(nums[idx]%2==0){
                s-=nums[idx];
            }
            nums[idx]+=val;

            if(nums[idx]%2==0){
                s+=nums[idx];
            }

                ans.push_back(s);
            
         }
         return ans;
    }
};