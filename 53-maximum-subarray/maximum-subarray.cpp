class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currentsum = nums[0];
        int ans = nums[0];
        int ansstart=0;
        int ansend=0;
        int start=0;

        for(int i = 1; i < nums.size(); i++) {

            // Choice:
            // 1. New subarray start karo
            // 2. Previous subarray continue karo
           if(nums[i]>(currentsum+nums[i])){
            currentsum=nums[i];
            start=i;
           }

           else{
            currentsum+=nums[i];
           }


           if(currentsum>ans){
            ansstart=start;
            ansend=i;
            ans=max(ans,currentsum);
           }
        }

        for(int i=ansstart;i<=ansend;i++){
            cout<<nums[i]<<" ";
        }

        return ans;
    }
};